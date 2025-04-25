using System;
using System.Collections.Generic;
using System.Linq;

namespace Hot100SU2025 {
    public class Solution279 {
        // 279-perfect-squares
        public int NumSquares(int n) {
            List<int> squareTable = [];
            for (int i = 0; i <= 100; ++i) {
                squareTable.Add(i * i);
            }

            // minimum number of squares required to reach value x
            List<int> dp = [.. Enumerable.Repeat(int.MaxValue, n + 1)];
            dp[0] = 0;

            for (int i = 1; i < dp.Count; ++i) {
                for (int j = 1; j < squareTable.Count; ++j) {
                    if (i - squareTable[j] >= 0) {
                        dp[i] = Math.Min(dp[i], dp[i - squareTable[j]] + 1);
                    }
                }
            }

            return dp[n];
        }
    }
}
