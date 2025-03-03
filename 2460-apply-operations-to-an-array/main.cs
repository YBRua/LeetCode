using System;

public class Solution {
    public int[] ApplyOperations(int[] nums) {
        int[] res = new int[nums.Length];
        for (int i = 0; i < nums.Length - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = 2 * nums[i];
                nums[i + 1] = 0;
            }
        }

        int j = 0;
        for (int i = 0; i < nums.Length; ++i) {
            if (nums[i] != 0) {
                res[j] = nums[i];
                ++j;
            }
        }

        return res;
    }
}
