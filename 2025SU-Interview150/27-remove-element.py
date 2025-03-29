from typing import List


# 27-remove-element
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        n_remaining = 0
        for j, num in enumerate(nums):
            if num != val:
                nums[i] = num
                i += 1
                n_remaining += 1

        return n_remaining
