using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 189-rotate-array
    public class Solution189 {
        private void Reverse(int[] nums, int start, int end) {
            while (start < end) {
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start++;
                end--;
            }
        }

        public void Rotate(int[] nums, int k) {
            Reverse(nums, 0, nums.Length - 1);
            Reverse(nums, 0, k % nums.Length - 1);
            Reverse(nums, k % nums.Length, nums.Length - 1);
        }
    }
}