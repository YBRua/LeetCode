using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 94-binary-tree-inorder-traversal
    public class Solution94 {
        public void Visitor(TreeNode current, List<int> res) {
            if (current == null) {
                return;
            }

            Visitor(current.left, res);
            res.Add(current.val);
            Visitor(current.right, res);

            return;
        }

        public IList<int> InorderTraversal(TreeNode root) {
            List<int> res = [];
            Visitor(root, res);

            return res;
        }

        public IList<int> InorderTraversalIterative(TreeNode root) {
            var res = new List<int>();
            var stack = new Stack<TreeNode>();
            var curr = root;

            while (curr != null || stack.Count > 0) {
                while (curr != null) {
                    stack.Push(curr);
                    curr = curr.left;
                }

                curr = stack.Pop();
                res.Add(curr.val);
                curr = curr.right;
            }

            return res;
        }
    }
}