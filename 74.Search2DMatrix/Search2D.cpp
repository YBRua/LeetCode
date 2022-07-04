#include <vector>

using namespace std;

class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n_rows = matrix.size();
        int n_cols = matrix[0].size();

        bool found = false;
        int row_low = 0, row_high = n_rows - 1;
        while (row_low < row_high) {
            int mid = (row_low + row_high) / 2;
            if (target <= matrix[mid][n_cols - 1] && target >= matrix[mid][0]) {
                // hit, in range of mid row
                row_low = row_high = mid;
                break;
            } else if (target > matrix[mid][n_cols - 1]) {
                row_low = mid + 1;
            } else if (target < matrix[mid][0]) {
                row_high = mid - 1;
            }
        }

        int col_low = 0, col_high = n_cols - 1;
        while (col_low < col_high) {
            int mid = (col_low + col_high) / 2;
            if (target < matrix[row_low][mid]) {
                col_high = mid - 1;
            } else if (target > matrix[row_low][mid]) {
                col_low = mid + 1;
            } else {
                // hit
                found = true;
                break;
            }
        }
        return found || matrix[row_low][col_low] == target;
    }
};
