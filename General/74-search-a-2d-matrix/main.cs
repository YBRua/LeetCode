// 74-search-a-2d-matrix
public class Solution74 {
    public bool SearchMatrix(int[][] matrix, int target) {
        int nRows = matrix.Length, nCols = matrix[0].Length;
        int top = 0, bottom = nRows - 1;
        while (top <= bottom) {
            int midRow = (top + bottom) / 2;
            if (matrix[midRow][0] <= target && target <= matrix[midRow][nCols - 1]) {

                int left = 0, right = nCols - 1;
                while (left <= right) {
                    int midCol = (left + right) / 2;
                    if (matrix[midRow][midCol] == target) {
                        return true;
                    } else if (matrix[midRow][midCol] < target) {
                        left = midCol + 1;
                    } else {
                        right = midCol - 1;
                    }
                }

                return false;

            } else if (matrix[midRow][0] < target) {
                top = midRow + 1;
            } else {
                bottom = midRow - 1;
            }
        }

        return false;
    }
}
