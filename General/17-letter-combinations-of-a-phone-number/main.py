from typing import List


# 17-letter-combinations-of-a-phone-number
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        table = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        res = []

        def _dfs_combiner(seq: List[str], idx: int):
            if len(seq) == len(digits):
                res.append("".join(seq))
                return

            curr = digits[idx]
            for c in table[curr]:
                seq.append(c)
                _dfs_combiner(seq, idx + 1)
                seq.pop()

        if digits:
            _dfs_combiner(list(), 0)

        return res
