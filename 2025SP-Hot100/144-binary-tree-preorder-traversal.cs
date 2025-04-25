using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    // 144-binary-tree-preorder-traversal
    public class Solution144 {
        public IList<int> PreorderTraversal(TreeNode root) {
            if (root == null) {
                return [];
            }

            List<int> res = [];
            Stack<TreeNode> stack = new();
            stack.Push(root);

            while (stack.Count > 0) {
                TreeNode curr = stack.Pop();
                res.Add(curr.val);

                if (curr.right != null) {
                    stack.Push(curr.right);
                }
                if (curr.left != null) {
                    stack.Push(curr.left);
                }
            }

            return res;
        }
    }
}