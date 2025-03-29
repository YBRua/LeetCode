from typing import List, Set


# 77-combinations
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        def _dfs_combiner(seq: List[int], curr: int, visited: Set[int]):
            if len(seq) == k:
                res.append(list(seq))
                return

            for i in range(curr + 1, n - (k - len(seq) - 1) + 1):
                if i in visited:
                    continue

                seq.append(i)
                visited.add(i)
                _dfs_combiner(seq, i, visited)
                visited.remove(i)
                seq.pop()

        _dfs_combiner(list(), 0, set())

        return res
