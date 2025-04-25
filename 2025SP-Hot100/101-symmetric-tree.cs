using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution101 {
        // 101-symmetric-tree
        public bool Match(TreeNode left, TreeNode right) {
            if (left == null && right == null) {
                return true;
            }
            if (left == null || right == null) {
                return false;
            }

            bool inner = Match(left.right, right.left);
            bool outer = Match(left.left, right.right);

            return left.val == right.val && inner && outer;
        }
        public bool IsSymmetric(TreeNode root) {
            return Match(root, root);
        }
    }
}
