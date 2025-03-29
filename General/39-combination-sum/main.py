from typing import List


# 39-combination-sum
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []

        def _dfs_combiner(seq: List[int], curr_sum: int):
            if curr_sum == target:
                res.append(list(seq))
                return

            if curr_sum > target:
                return

            for c in candidates:
                if seq and c < seq[-1]:
                    continue

                seq.append(c)
                _dfs_combiner(seq, curr_sum + c)
                seq.pop()

        _dfs_combiner(list(), 0)

        return res
