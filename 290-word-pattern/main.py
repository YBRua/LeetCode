# 290-word-pattern

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()

        if len(pattern) != len(words):
            return False

        pattern2word = {}
        word2pattern = {}
        for p, word in zip(pattern, words):
            if p not in pattern2word:
                pattern2word[p] = word
            elif pattern2word[p] != word:
                return False

            if word not in word2pattern:
                word2pattern[word] = p
            elif word2pattern[word] != p:
                return False

        return True
