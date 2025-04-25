using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution1 {
        // 1-two-sum
        public int[] TwoSum(int[] nums, int target) {
            Dictionary<int, int> dict = new();
            for (int i = 0; i < nums.Length; ++i) {
                int num = nums[i], candidate = target - num;
                if (dict.ContainsKey(candidate)) {
                    return new int[] { dict[candidate], i };
                }

                dict[num] = i;
            }

            return new int[] { -1, -1 };
        }
    }
}
