from typing import List


# 53-maximum-subarray
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-float("int")] * n

        dp[0] = nums[0]
        max_sum = -float("inf")

        for i in range(1, len(nums)):
            dp[i] = max(nums[i], dp[i - 1] + nums[i])
            max_sum = max(max_sum, dp[i])

        return max_sum
