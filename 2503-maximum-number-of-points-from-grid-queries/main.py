import heapq
from typing import List


# 2503-maximum-number-of-points-from-grid-queries
class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:
        n_rows = len(grid)
        n_cols = len(grid[0])

        sorted_queries = list(sorted(enumerate(queries), key=lambda x: x[1]))
        res = [0] * len(queries)

        OFFSETS = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        visited = set()
        total_points = 0
        pq = []

        heapq.heappush(pq, (grid[0][0], 0, 0))
        for q_id, q_value in sorted_queries:
            while len(pq) and pq[0][0] < q_value:
                cell_value, row, col = heapq.heappop(pq)

                total_points += 1
                visited.add((row, col))

                for drow, dcol in OFFSETS:
                    new_row, new_col = row + drow, col + dcol
                    if (
                        new_row >= 0
                        and new_row < n_rows
                        and new_col >= 0
                        and new_col < n_cols
                        and (new_row, new_col) not in visited
                    ):
                        heapq.heappush(pq, (grid[new_row][new_col], new_row, new_col))

            res[q_id] = total_points

        return res
