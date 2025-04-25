using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution121 {
        // 121-best-time-to-buy-and-sell-stock
        public int MaxProfit(int[] prices) {
            int cost = int.MaxValue;
            int profit = 0;
            for (int i = 0; i < prices.Length; ++i) {
                cost = Math.Min(cost, prices[i]);
                profit = Math.Max(profit, prices[i] - cost);
            }

            return profit;
        }
    }
}
