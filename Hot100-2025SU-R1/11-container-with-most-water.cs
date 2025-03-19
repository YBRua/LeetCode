using System;

namespace Hot100SU2025 {
    public class Solution11 {
        // 11-container-with-most-water
        public int MaxArea(int[] height) {
            int lp = 0, rp = height.Length - 1;
            int maxArea = 0;
            while (lp < rp) {
                int area = Math.Min(height[lp], height[rp]) * (rp - lp);
                if (maxArea < area) {
                    maxArea = area;
                }
                if (height[lp] < height[rp]) {
                    lp++;
                } else {
                    rp--;
                }
            }

            return maxArea;
        }
    }
}