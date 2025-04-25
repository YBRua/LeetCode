from collections import defaultdict
from typing import List


class Solution:
    # 2845-count-of-interesting-subarrays
    def countInterestingSubarrays(self, nums: List[int], modulo: int, k: int) -> int:
        n = len(nums)
        counts = [0] * (n + 1)

        for i, num in enumerate(nums):
            counts[i + 1] = counts[i] + int(num % modulo == k)

        res = 0
        mp = defaultdict(int)
        for i, cnt in enumerate(counts):
            curr = cnt % modulo
            remainder = (curr - k + modulo) % modulo

            res += mp[remainder]
            mp[curr] += 1

        return res
