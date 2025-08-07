from collections import Counter

def find_anagrams(word, candidates):
    results = []
    wc = Counter(word.lower())
    for candidate in candidates:
        cc = Counter(candidate.lower())
        if candidate.lower() != word.lower() and wc == cc:
            results.append(candidate)
    return results