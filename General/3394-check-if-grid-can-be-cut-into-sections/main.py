from typing import List


# 3394-check-if-grid-can-be-cut-into-sections
class Solution:
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        # check rows
        rows_sorted = list(sorted(rectangles, key=lambda x: x[0]))
        rows_buffer = [list(rows_sorted[0])]
        for i in range(1, len(rows_sorted)):
            if rows_sorted[i][0] < rows_buffer[-1][2]:
                rows_buffer[-1][2] = max(rows_sorted[i][2], rows_buffer[-1][2])
            else:
                rows_buffer.append(list(rows_sorted[i]))

        is_row_splittable = len(rows_buffer) >= 3

        # check columns
        cols_sorted = list(sorted(rectangles, key=lambda x: x[1]))
        cols_buffer = [list(cols_sorted[0])]
        for i in range(1, len(cols_sorted)):
            if cols_sorted[i][1] < cols_buffer[-1][3]:
                cols_buffer[-1][3] = max(cols_buffer[-1][3], cols_sorted[i][3])
            else:
                cols_buffer.append(list(cols_sorted[i]))

        is_col_splittable = len(cols_buffer) >= 3

        return is_row_splittable or is_col_splittable
