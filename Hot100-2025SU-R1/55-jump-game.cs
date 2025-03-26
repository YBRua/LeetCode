using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution55 {
        // 55-jump-game
        public bool CanJump(int[] nums) {
            int maxDistance = 0;
            int steps = 0;
            for (int i = 0; i < nums.Length; ++i) {
                if (i > maxDistance) {
                    return false;
                }

                if (i == maxDistance) {
                    steps += 1;
                }

                maxDistance = Math.Max(maxDistance, i + nums[i]);

                if (maxDistance >= nums.Length - 1) {
                    return true;
                }
            }

            return true;
        }
    }
}
