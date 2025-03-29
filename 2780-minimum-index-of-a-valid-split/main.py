from typing import List, Dict
from collections import defaultdict


# 2780-minimum-index-of-a-valid-split
class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        n = len(nums)
        freqs = defaultdict(int)

        for num in nums:
            freqs[num] += 1

        running_freqs = defaultdict(int)
        for i, num in enumerate(nums):
            running_freqs[num] += 1
            if (
                running_freqs[num] > (i + 1) // 2
                and freqs[num] - running_freqs[num] > (n - i - 1) // 2
            ):
                return i

        return -1
