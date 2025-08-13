class SgfTree:
    def __init__(self, properties=None, children=None):
        self.properties = properties or {}
        self.children = children or []

    def __eq__(self, other):
        if not isinstance(other, SgfTree):
            return False
        for key, value in self.properties.items():
            if key not in other.properties:
                return False
            if other.properties[key] != value:
                return False
        for key in other.properties.keys():
            if key not in self.properties:
                return False
        if len(self.children) != len(other.children):
            return False
        for child, other_child in zip(self.children, other.children):
            if child != other_child:
                return False
        return True

    def __ne__(self, other):
        return not self == other

def parse(input_string):
    # Basic guards to match your earlier behavior/messages
    if input_string is None or input_string == "" or input_string == ";":
        raise ValueError("tree missing")
    s = input_string.strip()
    if s == "()":
        raise ValueError("tree with no nodes")

    # Recursive descent parser
    i = 0

    def peek():
        return s[i] if i < len(s) else None

    def expect(ch):
        nonlocal i
        if peek() != ch:
            raise ValueError("tree with no nodes")
        i += 1

    def parse_value():
        """Parse one [ ... ] value with SGF-style escapes and whitespace normalization:
           - Unescaped tabs -> space
           - Escaped tabs (\\ + \t) -> space
           - Escaped newline (\\ + \n or \r\n or \r) -> removed (line continuation)
           - \\] -> ']', \\\\ -> '\\'
           - Other escaped chars are taken literally
           - Unescaped newlines are preserved
        """
        nonlocal i
        expect('[')
        buf = []
        while True:
            if i >= len(s):
                raise ValueError("properties without delimiter")
            c = s[i]; i += 1
    
            if c == '\\':
                if i >= len(s):
                    # lone trailing backslash inside value; treat as literal backslash
                    buf.append('\\')
                    continue
                nxt = s[i]; i += 1
    
                # Escaped newline handling: \r\n, \n, or \r
                if nxt == '\r':
                    # swallow optional \n after \r
                    if i < len(s) and s[i] == '\n':
                        i += 1
                    # line continuation -> append nothing
                    continue
                elif nxt == '\n':
                    # line continuation -> append nothing
                    continue
                elif nxt == '\t':
                    buf.append(' ')
                elif nxt in (']', '\\'):
                    buf.append(nxt)
                else:
                    # keep other escaped chars literally
                    buf.append(nxt)
    
            elif c == ']':
                break
            else:
                if c == '\t':
                    buf.append(' ')
                else:
                    buf.append(c)
    
        return "".join(buf)
        
    def parse_prop_ident():
        """Read PROPIDENT (A-Z+). Raise proper errors for mixed/lowercase."""
        nonlocal i
        start = i
    
        # Must start with uppercase A-Z
        if i >= len(s) or not ('A' <= s[i] <= 'Z'):
            ch = peek()
            if ch == '[':
                # Saw a value without a preceding key
                raise ValueError("properties without delimiter")
            if ch and ch.isalpha() and ch != ch.upper():
                # Lowercase where a key is expected
                raise ValueError("property must be in uppercase")
            return None  # let caller decide if sequence ended
        # Consume consecutive uppercase letters
        while i < len(s) and 'A' <= s[i] <= 'Z':
            i += 1
    
        # If the very next char is a lowercase letter, it's a mixed-case key → error
        if i < len(s) and s[i].isalpha() and s[i] != s[i].upper():
            raise ValueError("property must be in uppercase")
    
        return s[start:i]

    def parse_node():
        """Parse one ;node with zero or more properties."""
        nonlocal i
        if peek() != ';':
            raise ValueError("tree with no nodes")
        i += 1  # consume ';'
        node = SgfTree()

        # Zero or more properties until we hit ';', '(' or ')'
        while True:
            ch = peek()
            if ch in (None, ';', '(', ')'):
                break  # end of properties in this node
            key = parse_prop_ident()
            if key is None:
                # If we’re here, we saw a non-property token outside of [].
                # SGF doesn’t allow that; treat as uppercase error.
                raise ValueError("property must be in uppercase")
            # At least one [value]
            if peek() != '[':
                raise ValueError("properties without delimiter")
            vals = []
            while peek() == '[':
                vals.append(parse_value())
            node.properties.setdefault(key, []).extend(vals)
        return node

    def link_sequence(nodes):
        """Convert a list of nodes into a linear chain via .children."""
        if not nodes:
            return None, None
        for a, b in zip(nodes, nodes[1:]):
            a.children = [b]
        return nodes[0], nodes[-1]

    def parse_sequence():
        """Sequence = Node { Node } (linear chain)."""
        nodes = []
        while peek() == ';':
            nodes.append(parse_node())
        if not nodes:
            raise ValueError("tree with no nodes")
        return link_sequence(nodes)  # (root_of_chain, tail_of_chain)

    def parse_gametree():
        """GameTree = '(' Sequence { GameTree } ')'"""
        nonlocal i
        expect('(')
        root, tail = parse_sequence()

        # Variations: children of the last node in the sequence
        while peek() == '(':
            child = parse_gametree()
            tail.children.append(child)

        expect(')')
        return root

    root = parse_gametree()

    # If there’s trailing junk, you could validate/raise. For now we accept exact consumption.
    if i != len(s):
        # You can choose to enforce full consumption if your tests require it:
        # raise ValueError("tree missing")
        pass

    return root
