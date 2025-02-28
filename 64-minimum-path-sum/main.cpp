#include <vector>
using namespace std;

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        res[m - 1][n - 1] = grid[m - 1][n - 1];

        for (int row = m - 1; row >= 0; row--) {
            for (int col = n - 1; col >= 0; col--) {
                if (row == m - 1 && col == n - 1) {
                    continue;
                }

                if (row + 1 >= m) {
                    res[row][col] = res[row][col + 1] + grid[row][col];
                } else if (col + 1 >= n) {
                    res[row][col] = res[row + 1][col] + grid[row][col];
                } else {
                    res[row][col] = min(res[row + 1][col], res[row][col + 1]) + grid[row][col];
                }
            }
        }

        return res[0][0];
    }
};
