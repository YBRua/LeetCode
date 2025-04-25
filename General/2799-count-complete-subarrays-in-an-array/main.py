from collections import defaultdict
from typing import List


class Solution:
    def countCompleteSubarrays(self, nums: List[int]) -> int:
        window_counter = defaultdict(int)
        n_distinct_in_window = 0
        n_distinct_items = len(set(nums))

        n_complete_arrays = 0
        left = 0
        right = 0

        while right < len(nums):
            if window_counter[nums[right]] == 0:
                n_distinct_in_window += 1

            window_counter[nums[right]] += 1

            while n_distinct_in_window == n_distinct_items:
                n_complete_arrays += len(nums) - right
                window_counter[nums[left]] -= 1

                if window_counter[nums[left]] == 0:
                    n_distinct_in_window -= 1

                left += 1

            right += 1

        return n_complete_arrays
