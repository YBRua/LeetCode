using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 240-search-a-2d-matrix-ii
    public class Solution240 {
        public bool SearchMatrix(int[][] matrix, int target) {
            // forms a binary search tree if we start from top right corner
            int row = 0, col = matrix[0].Length - 1;
            while (row < matrix.Length && col >= 0) {
                if (matrix[row][col] == target) {
                    return true;
                } else if (matrix[row][col] > target) {
                    col--;
                } else {
                    row++;
                }
            }

            return false;
        }
    }
}