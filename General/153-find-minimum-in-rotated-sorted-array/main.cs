// 153-find-minimum-in-rotated-sorted-array
using System;

public class Solution153 {
    public int FindMin(int[] nums) {
        int left = 0, right = nums.Length - 1;
        int min = nums[0];

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[0] <= nums[mid]) {
                // lhs is ordered
                left = mid + 1;
                if (left < nums.Length) {
                    min = Math.Min(nums[left], min);
                }
            } else {
                // right is ordered
                right = mid - 1;
            }
        }

        return min;
    }
}
