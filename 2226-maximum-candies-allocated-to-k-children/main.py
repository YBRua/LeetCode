# 2226-maximum-candies-allocated-to-k-children
from typing import List


class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        left = 0
        right = max(candies)

        result = 0
        while left < right:
            mid = (left + right) // 2

            k_available = 0
            for pile in candies:
                k_available += pile // mid

            if k_available < k:
                right = mid - 1
            else:
                result = mid
                left = mid + 1

        return result
