using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 73-set-matrix-zeroes
    public class Solution73 {
        public void SetZeroes(int[][] matrix) {
            HashSet<int> rowSet = new HashSet<int>();
            HashSet<int> colSet = new HashSet<int>();

            int nRows = matrix.Length;
            int nCols = matrix[0].Length;

            for (int row = 0; row < nRows; row++) {
                for (int col = 0; col < nCols; col++) {
                    if (matrix[row][col] == 0) {
                        rowSet.Add(row);
                        colSet.Add(col);
                    }
                }
            }

            foreach (int rowidx in rowSet) {
                for (int col = 0; col < nCols; col++) {
                    matrix[rowidx][col] = 0;
                }
            }

            foreach (int colidx in colSet) {
                for (int row = 0; row < nRows; row++) {
                    matrix[row][colidx] = 0;
                }
            }
        }
    }
}