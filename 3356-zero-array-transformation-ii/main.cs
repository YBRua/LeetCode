// 3356-zero-array-transformation-ii

using System;

public class Solution3356 {
    private bool CanFormZeroArray(int[] nums, int[][] queries, int k) {
        int[] diff = new int[nums.Length + 1];

        for (int i = 0; i < k; ++i) {
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1] + 1] -= queries[i][2];
        }

        int prefix_sum = 0;
        for (int i = 0; i < nums.Length; ++i) {
            prefix_sum += diff[i];
            if (nums[i] > prefix_sum) {
                return false;
            }
        }

        return true;
    }

    public int MinZeroArray(int[] nums, int[][] queries) {
        int left = 0, right = queries.Length;

        if (!CanFormZeroArray(nums, queries, right)) {
            return -1;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (CanFormZeroArray(nums, queries, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
}
