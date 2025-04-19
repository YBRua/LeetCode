from typing import List


# 47-permutations-ii
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        visited = [False] * len(nums)

        res = []

        def _dfs(idx: int, curr: List[int]):
            if len(curr) == len(nums):
                res.append(curr.copy())
                return

            for i in range(len(nums)):
                if visited[i] or (i > 0 and nums[i] == nums[i - 1] and not visited[i - 1]):
                    continue

                curr.append(nums[i])
                visited[i] = True
                _dfs(idx + 1, curr)
                visited[i] = False
                curr.pop()

        _dfs(0, [])

        return res
