using System;
using System.Collections.Generic;
using System.Linq;

namespace Hot100SU2025 {
    public class Solution84 {
        // 84-largest-rectangle-in-histogram
        public int LargestRectangleArea(int[] heights) {
            Stack<int> stack = new();
            List<int> left = [.. Enumerable.Repeat(-1, heights.Length)];
            List<int> right = [.. Enumerable.Repeat(-1, heights.Length)];

            for (int i = 0; i < heights.Length; ++i) {
                while (stack.Count > 0 && heights[stack.Peek()] >= heights[i]) {
                    stack.Pop();
                }
                left[i] = stack.Count > 0 ? stack.Peek() : -1;
                stack.Push(i);
            }

            stack.Clear();
            for (int i = heights.Length - 1; i >= 0; --i) {
                while (stack.Count > 0 && heights[stack.Peek()] >= heights[i]) {
                    stack.Pop();
                }
                right[i] = stack.Count > 0 ? stack.Peek() : heights.Length;
                stack.Push(i);
            }

            int maxArea = 0;
            for (int i = 0; i < heights.Length; ++i) {
                maxArea = Math.Max(maxArea, (right[i] - left[i] - 1) * heights[i]);
            }

            return maxArea;
        }
    }
}
