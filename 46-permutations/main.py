from typing import List, Set


class Solution:
    # 46-permutations
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []

        def _dfs_permuter(seq: List[int], visited: Set[int]):
            if len(seq) == len(nums):
                res.append(list(seq))

            for n in nums:
                if n in visited:
                    continue

                seq.append(n)
                visited.add(n)
                _dfs_permuter(seq, visited)
                visited.remove(n)
                seq.pop()

        _dfs_permuter(list(), set())

        return res
