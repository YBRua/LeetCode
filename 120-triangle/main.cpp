#include <vector>
using namespace std;

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // minimum sum from dp[i][j] to bottom
        vector<vector<int>> dp(n, vector<int>(n));

        // init and compute bottom-up
        // for the last row, minimum sum is the last row of triangle
        for (int j = 0; j < n; ++j) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0];
    }
};
