#include <vector>
using namespace std;


// in hind sight, using for loops would have been easier
class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_ptr = 0;
        int col_ptr = 0;
        int n_rows = matrix.size(), n_cols = matrix[0].size();
        int left = 0, right = n_cols, up = 0, down = n_rows;
        int expected_nums = n_rows * n_cols;

        vector<int> res;
        while (up < down && left < right) {
            // upper row
            row_ptr = up;
            col_ptr = left;
            while (col_ptr < right) {
                res.push_back(matrix[row_ptr][col_ptr]);
                col_ptr++;
                if (res.size() == expected_nums) {
                    break;
                }
            }
            up += 1;

            // right column
            row_ptr = up;
            col_ptr = right - 1;
            while (row_ptr < down) {
                res.push_back(matrix[row_ptr][col_ptr]);
                row_ptr++;
                if (res.size() == expected_nums) {
                    break;
                }
            }
            right -= 1;

            if (left >= right || up >= down) {
                break;
            }

            // lower row
            row_ptr = down - 1;
            col_ptr = right - 1;
            while (col_ptr >= left) {
                res.push_back(matrix[row_ptr][col_ptr]);
                col_ptr--;
                if (res.size() == expected_nums) {
                    break;
                }
            }
            down -= 1;

            // left column
            row_ptr = down - 1;
            col_ptr = left;
            while (row_ptr >= up) {
                res.push_back(matrix[row_ptr][col_ptr]);
                row_ptr--;
                if (res.size() == expected_nums) {
                    break;
                }
            }
            left += 1;
        }

        return res;
    }
};
