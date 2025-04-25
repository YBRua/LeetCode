using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution122 {
        // 122-best-time-to-buy-and-sell-stock-ii
        public int MaxProfit(int[] prices) {
            int[,] dp = new int[prices.Length, 2];
            dp[0, 0] = 0;
            dp[0, 1] = -prices[0];
            for (int i = 1; i < prices.Length; ++i) {
                dp[i, 0] = Math.Max(dp[i - 1, 0], dp[i - 1, 1] + prices[i]);
                dp[i, 1] = Math.Max(dp[i - 1, 1], dp[i - 1, 0] - prices[i]);
            }

            return dp[prices.Length - 1, 0];
        }
    }
}
