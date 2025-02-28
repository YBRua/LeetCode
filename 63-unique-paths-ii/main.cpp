#include <vector>
using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> res(m, vector<long long>(n, 0));

        if (obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) {
            return 0;
        }

        res[m - 1][n - 1] = 1;

        for (int row = m - 2; row >= 0; --row) {
            if (obstacleGrid[row][n - 1]) {
                res[row][n - 1] = 0;
            } else {
                res[row][n - 1] = res[row + 1][n - 1];
            }
        }
        for (int col = n - 2; col >= 0; --col) {
            if (obstacleGrid[m - 1][col]) {
                res[m - 1][col] = 0;
            } else {
                res[m - 1][col] = res[m - 1][col + 1];
            }
        }

        for (int row = m - 2; row >= 0; --row) {
            for (int col = n - 2; col >= 0; --col) {
                if (obstacleGrid[row][col]) {
                    res[row][col] = 0;
                    continue;
                }

                if (obstacleGrid[row][col + 1] != 1) {
                    res[row][col] += res[row][col + 1];
                }
                if (obstacleGrid[row + 1][col] != 1) {
                    res[row][col] += res[row + 1][col];
                }
            }
        }

        return res[0][0];
    }
};
