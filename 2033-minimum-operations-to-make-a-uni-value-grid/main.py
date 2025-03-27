from typing import List


# 2033-minimum-operations-to-make-a-uni-value-grid
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        flattened = []
        for row in grid:
            for item in row:
                if item % x != grid[0][0] % x:
                    return -1
                flattened.append(item)

        flattened = list(sorted(flattened))

        median = flattened[len(flattened) // 2]
        tot_ops = 0
        for item in flattened:
            tot_ops += abs(item - median) // x

        return tot_ops
