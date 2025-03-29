from typing import List


# 26-remove-duplicates-from-sorted-array
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        slow = 0
        fast = 0
        n_remaining = 1

        while fast < len(nums):
            while fast < len(nums) and nums[slow] == nums[fast]:
                fast += 1

            if fast < len(nums):
                slow += 1
                nums[slow] = nums[fast]
                n_remaining += 1

        return n_remaining
