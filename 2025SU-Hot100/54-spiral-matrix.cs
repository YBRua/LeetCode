using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 54-sprial-matrix
    public class Solution54 {
        public IList<int> SpiralOrder(int[][] matrix) {
            int nRows = matrix.Length;
            int nCols = matrix[0].Length;
            int totElements = nRows * nCols;
            List<int> res = new List<int>();

            int left = 0, right = nCols - 1;
            int top = 0, bottom = nRows - 1;

            while (left <= right && top <= bottom) {
                for (int i = left; i <= right; i++) {
                    res.Add(matrix[top][i]);
                }
                for (int i = top + 1; i <= bottom; i++) {
                    res.Add(matrix[i][right]);
                }
                if (left < right && top < bottom) {
                    for (int i = right - 1; i >= left; i--) {
                        res.Add(matrix[bottom][i]);
                    }
                    for (int i = bottom - 1; i > top; i--) {
                        res.Add(matrix[i][left]);
                    }
                }

                top++;
                bottom--;
                left++;
                right--;
            }

            return res;
        }
    }
}