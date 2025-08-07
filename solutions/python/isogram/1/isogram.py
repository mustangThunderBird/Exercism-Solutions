from collections import Counter

def is_isogram(string):
    counts = Counter(string.upper())
    for item,count in counts.items():
        if item not in ["-", " "] and count != 1:
            return False

    return True