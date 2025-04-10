using System;
using System.Collections.Generic;
using System.Linq;

namespace Hot100SU2025 {
    public class Solution416 {
        // 416-partition-equal-subset-sum
        public bool CanPartition(int[] nums) {
            if (nums.Length < 2) {
                return false;
            }

            int tot = nums.Sum();
            if (tot % 2 != 0) {
                return false;
            }

            int target = tot / 2;
            bool[,] dp = new bool[nums.Length, target + 1];

            if (nums[0] <= target) {
                dp[0, nums[0]] = true;
            }
            for (int i = 0; i < nums.Length; ++i) {
                dp[i, 0] = true;
            }

            for (int i = 1; i < nums.Length; ++i) {
                for (int j = 1; j <= target; ++j) {
                    if (j < nums[i]) {
                        dp[i, j] = dp[i - 1, j];
                    } else {
                        dp[i, j] = dp[i - 1, j] || dp[i - 1, j - nums[i]];
                    }
                }
            }

            return dp[nums.Length - 1, target];
        }
    }
}
