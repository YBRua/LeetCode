public class Solution {
    public int UniquePaths(int m, int n) {
        var dp = new int[m, n];
        
        // init
        dp[m-1, n-1] = 0;
        for (int i = m - 1; i >= 0; --i) {
            dp[i, n-1] = 1;
        }
        for (int j = n - 1; j >= 0; --j) {
            dp[m-1, j] = 1;
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i, j] = dp[i+1, j] + dp[i, j+1];
            }
        }

        return dp[0, 0];
    }
}
