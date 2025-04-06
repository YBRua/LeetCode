from typing import List


class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()

        n = len(nums)
        dp = [1] * n
        prev = [-1] * n
        max_i = 0

        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0 and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1
                    prev[i] = j

            if dp[i] > dp[max_i]:
                max_i = i

        res = []
        curr = max_i
        while curr != -1:
            res.append(nums[curr])
            curr = prev[curr]

        return res
