using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 48-rotate-image
    public class Solution48 {
        public void Rotate(int[][] matrix) {
            int nRows = matrix.Length;
            int nCols = matrix[0].Length;

            for (int i = 0; i < nRows / 2; ++i) {
                for (int j = 0; j < (nCols + 1) / 2; ++j) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[nRows - 1 - j][i];
                    matrix[nCols - 1 - j][i] = matrix[nRows - 1 - i][nCols - 1 - j];
                    matrix[nRows - 1 - i][nCols - 1 - j] = matrix[j][nRows - 1- i];
                    matrix[j][nRows - 1 - i] = temp;
                }
            }
        }
    }
}