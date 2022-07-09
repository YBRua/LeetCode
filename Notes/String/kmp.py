from typing import List


def prefix_function(s: str) -> List[int]:
    n = len(s)
    res = [0] * n
    for i in range(1, n):
        j = res[i - 1]
        while j > 0 and s[i] != s[j]:
            j = res[j - 1]
        if s[i] == s[j]:
            j += 1
        res[i] = j

    return res


def kmp(string: str, pattern: str):
    ls = len(string)
    lp = len(pattern)

    # backtracking lookup array
    # this is used for skipping characters
    # in the pattern that are already matched
    nexts = prefix_function(pattern)

    begin_indices = []
    i = 0
    j = 0
    # match until the end of the target string
    while i < ls:
        # if current two chars are equal, move forward
        if string[i] == pattern[j]:
            i += 1
            j += 1
        # pattern matched, note down result
        # and use prefix lookup to backtrack
        if j == lp:
            begin_indices.append(i - j)
            j = nexts[j - 1]
        # current chars are not equal, consider backtracking
        elif i < ls and string[i] != pattern[j]:
            # backtracking
            if j != 0:
                j = nexts[j - 1]
            # if backtracking to the beginning of the pattern,
            # move to the next char in the target string
            else:
                i += 1
    return begin_indices


def _prefix_function(s: str):
    n = len(s)
    res = [0] * n
    for i in range(1, n):
        j = res[i - 1]
        while j > 0 and s[i] != s[j]:
            j = res[j - 1]
        if s[i] == s[j]:
            j += 1
        res[i] = j
    return res


def _recite_kmp(source: str, pattern: str) -> List:
    nexts = _prefix_function(pattern)
    res = []
    i, j = 0, 0
    while i < len(source):
        if source[i] == pattern[j]:
            i += 1
            j += 1
        if j == len(pattern):
            res.append(i - j)
            j = nexts[j - 1]
        elif i < len(source) and source[i] != pattern[j]:
            if j > 0:
                j = nexts[j - 1]
            else:
                i += 1
    return res


print(_prefix_function('aaaaaaaa'))

source = 'abcdabcdabab'
pattern = 'ab'

hits = _recite_kmp(source, pattern)
for hit in hits:
    print(f'hit at {hit}')
