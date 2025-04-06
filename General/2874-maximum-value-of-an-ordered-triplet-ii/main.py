from typing import List


class Solution:
    # 2874-maximum-value-of-an-ordered-triplet-ii
    def maximumTripletValue(self, nums: List[int]) -> int:
        n = len(nums)
        prefix_maxs = [0] * n
        suffix_maxs = [0] * n

        prefix_maxs[0] = nums[0]
        for i in range(1, n):
            prefix_maxs[i] = max(nums[i], prefix_maxs[i - 1])

        suffix_maxs[-1] = nums[-1]
        for j in range(n - 2, 0, -1):
            suffix_maxs[j] = max(nums[j], suffix_maxs[j + 1])

        # given j, (nums[i] - nums[j]) * nums[k] achieves maximum value when
        # nums[i] and nums[k] take the largest value in [0, j) and (j, n-1]
        max_val = 0
        for j in range(1, n - 1):
            val = (prefix_maxs[j - 1] - nums[j]) * suffix_maxs[j + 1]
            max_val = max(max_val, val)

        return max_val
