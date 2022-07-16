using System;
using System.Collections.Generic;

public class Solution {
    public int FindPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // dp[i][j] = temp[i-1][j] + temp[i+1][j] + temp[i][j-1] + temp[i][j+1]
        var dp = new int[m, n];
        dp[startRow, startColumn] = 1;
        int count = 0;
        int MOD = Convert.ToInt32(1e9) + 7;
        for (int k = 1; k <= maxMove; ++k) {
            var temp = new int[m, n];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == 0) {
                        count = (count + dp[i, j]) % MOD;
                    }
                    if (j == 0) {
                        count = (count + dp[i, j]) % MOD;
                    }
                    if (i == m - 1) {
                        count = (count + dp[i, j]) % MOD;
                    }
                    if (j == n - 1) {
                        count = (count + dp[i, j]) % MOD;
                    }
                    int prevRow = i > 0 ? dp[i - 1, j] : 0;
                    int prevCol = j > 0 ? dp[i, j - 1] : 0;
                    int nextRow = i < m - 1 ? dp[i + 1, j] : 0;
                    int nextCol = j < n - 1 ? dp[i, j + 1] : 0;
                    temp[i, j] = ((prevRow + prevCol) % MOD + (nextRow + nextCol) % MOD) % MOD;
                }
            }
            dp = temp;
        }

        return count;
    }
}
