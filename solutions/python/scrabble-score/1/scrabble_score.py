def score(word):
    scores = {
        frozenset(["A", "E", "I", "O", "U", "L", "N", "R", "S", "T"]) : 1,
        frozenset(["D","G"]) : 2,
        frozenset(["B", "C", "M", "P"]) : 3,
        frozenset(["F", "H", "V", "W", "Y"]) : 4,
        frozenset(["K"]) : 5,
        frozenset(["J","X"]) : 8,
        frozenset(["Q","Z"]) : 10
    }
    total = 0
    for letter in word.upper():
        for letters in scores.keys():
            if letter in letters:
                total += scores[letters]
    return total