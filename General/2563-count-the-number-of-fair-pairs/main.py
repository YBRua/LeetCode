from typing import List


class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        # 2563-count-the-number-of-fair-pairs
        # sorting wouldnt affect the result as nums[i] + nums[j] == nums[j] + nums[i]
        nums.sort()
        return self._lower_bound(nums, upper + 1) - self._lower_bound(nums, lower)

    def _lower_bound(self, nums: List[int], thres: int):
        # count number of pairs whose sum is smaller than thres
        left = 0
        right = len(nums) - 1
        count = 0
        while left < right:
            if nums[left] + nums[right] < thres:
                count += right - left
                left += 1
            else:
                right -= 1

        return count
