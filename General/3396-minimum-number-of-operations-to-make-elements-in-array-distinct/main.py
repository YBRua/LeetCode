import math
from typing import List


# 3396-minimum-number-of-operations-to-make-elements-in-array-distinct
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        right = len(nums) - 1
        visited = set()

        while right >= 0:
            if nums[right] in visited:
                break

            visited.add(nums[right])
            right -= 1

        n_removals = math.ceil((right + 1) / 3)

        return n_removals
