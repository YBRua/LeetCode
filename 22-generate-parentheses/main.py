from typing import List


# 22-generate-parentheses
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def _dfs_generator(curr: str, tot_openings: int, curr_openings: int):
            if len(curr) == 2 * n:
                res.append(curr)
                return

            if tot_openings < n:
                _dfs_generator(curr + "(", tot_openings + 1, curr_openings + 1)
                if curr_openings > 0:
                    _dfs_generator(curr + ")", tot_openings, curr_openings - 1)
            else:
                _dfs_generator(curr + ")", tot_openings, curr_openings - 1)

        _dfs_generator("", 0, 0)

        return res
