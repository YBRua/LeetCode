from typing import List


class Solution:
    # 2302-count-subarrays-with-score-less-than-k
    def countSubarrays(self, nums: List[int], k: int) -> int:
        left = 0
        right = 0
        tot = 0
        running_sum = 0

        while right < len(nums):
            running_sum += nums[right]
            score = (right - left + 1) * running_sum

            while score >= k:
                running_sum -= nums[left]
                left += 1
                score = (right - left + 1) * running_sum

            tot += right - left + 1
            right += 1

        return tot
