from typing import List


class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)

        # whether substring of length i could be constructed
        dp = [True] + [False] * n

        word_set = set(wordDict)

        for i in range(1, n + 1):
            for j in range(0, i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True

        return dp[n]
