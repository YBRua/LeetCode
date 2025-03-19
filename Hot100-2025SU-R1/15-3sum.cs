using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution15 {
        // 15-3sum
        public IList<IList<int>> ThreeSum(int[] nums) {
            Array.Sort(nums);
            List<List<int>> res = new();
            for (int first = 0; first < nums.Length; ++first) {
                if (nums[first] > 0) {
                    break;
                }

                if (first > 0 && nums[first] == nums[first - 1]) {
                    continue;
                }

                int third = nums.Length - 1;
                for (int second = first + 1; second < nums.Length; ++second) {
                    if (second > first + 1 && nums[second] == nums[second - 1]) {
                        continue;
                    }

                    while (third > second && nums[first] + nums[second] + nums[third] > 0) {
                        third--;
                    }
                    if (third == second) {
                        break;
                    }
                    if (nums[first] + nums[second] + nums[third] == 0) {
                        res.Add(new List<int> { nums[first], nums[second], nums[third] });
                    }
                }
            }

            return res.ToArray();
        }
    }
}