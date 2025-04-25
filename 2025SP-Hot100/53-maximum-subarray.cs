using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 53-maximum-subarray
    public class Solution53 {
        public int MaxSubArray(int[] nums) {
            int[] dp = new int[nums.Length];
            dp[0] = nums[0];

            for (int i = 1; i < nums.Length; i++) {
                dp[i] = Math.Max(dp[i - 1] + nums[i], nums[i]);
            }

            return dp.Max();
        }
    }
}