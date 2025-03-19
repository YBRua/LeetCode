using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution42 {
        // 42-trapping-rain-water
        public int Trap(int[] height) {
            int[] leftMax = new int[height.Length];
            int[] rightMax = new int[height.Length];

            leftMax[0] = height[0];
            rightMax[^1] = height[^1];

            for (int i = 1; i < height.Length; ++i) {
                leftMax[i] = Math.Max(leftMax[i - 1], height[i]);
            }
            for (int j = height.Length - 2; j >= 0; --j) {
                rightMax[j] = Math.Max(rightMax[j + 1], height[j]);
            }

            int trappedWater = 0;
            for (int i = 0; i < height.Length; ++i) {
                trappedWater += Math.Min(leftMax[i], rightMax[i]) - height[i];
            }

            return trappedWater;
        }
    }
}
