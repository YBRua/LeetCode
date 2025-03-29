# 2560-house-robber-iv
from typing import List


class Solution:
    def _can_steal_k_houses_with(self, capability: int, nums: List[int], k: int) -> bool:
        i = 0
        cnt = 0
        while i < len(nums):
            if nums[i] <= capability:
                cnt += 1
                i += 2
            else:
                i += 1

        return cnt >= k

    def minCapability(self, nums: List[int], k: int) -> int:
        left = min(nums)
        right = max(nums)

        res = 0
        while left <= right:
            mid = (left + right) // 2
            if self._can_steal_k_houses_with(mid, nums, k):
                res = mid
                right = mid - 1
            else:
                left = mid + 1

        return res
