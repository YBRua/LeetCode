using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 41-first-missing-positive
    public class Solution41 {
        public int FirstMissingPositive(int[] nums) {
            // for an array of length n, the result must be in [1, n+1]
            // 1. if all first n positive numbers are in the array, then the result is n+1
            // 2. otherwise, the result is in [1, n]
            // so we can perform an in-place hash that puts each number n at index n-1
            // e.g., [1, 3, -1, 4] -> [1, -1, 3, 4], where we can easily identify 2 as the missing number

            for (int i = 0; i < nums.Length; ++i) {
                // repeatedly swap nums[i] until nums[i] has either the correct value or is out of range
                while (nums[i] > 0 && nums[i] <= nums.Length && nums[nums[i] - 1] != nums[i]) {
                    (nums[nums[i] - 1], nums[i]) = (nums[i], nums[nums[i] - 1]);
                }
            }

            for (int i = 0; i < nums.Length; ++i) {
                if (nums[i] != i + 1) {
                    return i + 1;
                }
            }

            return nums.Length + 1;
        }
    }
}