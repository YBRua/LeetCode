#include <vector>
#include <cstdio>

using namespace std;

/**
 * dp[i][j]: #sets of non-overlapping j line segments, covering first i points
 * dp[i][j] =   dp[i-1][j] (i is not covered)
 *              + dp[i-1][j-1] (i covered by line seg of length 1)
 *              + dp[i-2][j-1] (i covered by line seg of length 2)
 *              + ...
 *              + dp[j][j-1] (i covered by line seg of length j)
 */

class Solution {
   public:
    int numberOfSets(int n, int k) {
        const int M = 1000000007;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<int> prefix_sums(k + 1, 0);

        for (int i = 1; i <= n; ++i) {  // number of nodes to cover
            dp[i][0] = 1;
            for (int j = 1; j < min(i, k+1); ++j) {  // number of lines to use
                dp[i][j] = (prefix_sums[j - 1] + dp[i-1][j]) % M;
            }
            for (int j = 0; j <= k; ++j) {
                prefix_sums[j] = (dp[i][j] + prefix_sums[j]) % M;
            }
        }

        // for (int i = 0; i <= n; ++i) {
        //     for (int j = 0; j <= k; ++j) {
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }

        return dp[n][k];
    }
};

int main() {
    printf("%d\n", Solution().numberOfSets(4, 2));
    return 0;
}
