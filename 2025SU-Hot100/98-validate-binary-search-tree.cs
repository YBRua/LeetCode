using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution98 {
        // 98-validate-binary-search-tree
        public bool IsValidBST(TreeNode root) {
            Stack<TreeNode> stk = new();
            TreeNode curr = root;

            int? prev = null;
            while (stk.Count > 0 || curr != null) {
                while (curr != null) {
                    stk.Push(curr);
                    curr = curr.left;
                }
                curr = stk.Pop();

                if (prev != null && curr.val <= prev) {
                    return false;
                }

                prev = curr.val;
                curr = curr.right;
            }

            return true;
        }
    }
}
