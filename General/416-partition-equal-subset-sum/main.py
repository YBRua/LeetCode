from typing import List


class Solution:
    # 416-partition-equal-subset-sum
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 2:
            return False

        tot_sum = sum(nums)
        if tot_sum % 2 != 0:
            return False

        target = tot_sum // 2
        # dp[i, j]: can achieve total sum of j using first i items in nums
        dp = [[False for _ in range(target + 1)] for _ in range(n)]

        for i in range(n):
            dp[i][0] = True

        if nums[0] <= target:
            dp[0][nums[0]] = True

        for i in range(1, n):
            for j in range(target + 1):
                if j < nums[i]:
                    dp[i][j] = dp[i - 1][j]
                else:
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]]

        return dp[n - 1][target]
