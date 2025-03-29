# 2594-minimum-time-to-repair-cars
import math
from typing import List


class Solution:
    def repairCars(self, ranks: List[int], cars: int) -> int:
        left = 0
        right = max(ranks) * cars**2

        res = 0
        while left <= right:
            mid = (left + right) // 2
            tot_capacity = sum(int(math.sqrt(mid // rank)) for rank in ranks)

            if tot_capacity >= cars:
                res = mid
                right = mid - 1
            else:
                left = mid + 1

        return res
