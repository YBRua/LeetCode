using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution108 {
        public TreeNode build(int[] nums, int left, int right) {
            if (left > right) {
                return null;
            }

            int mid = (left + right) / 2;
            var curr = new TreeNode(nums[mid]);

            curr.left = build(nums, left, mid - 1);
            curr.right = build(nums, mid + 1, right);

            return curr;
        }

        // 108-convert-sorted-array-to-binary-search-tree
        public TreeNode SortedArrayToBST(int[] nums) {
            return build(nums, 0, nums.Length - 1);
        }
    }
}
