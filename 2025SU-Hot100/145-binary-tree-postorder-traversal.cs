using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    // 145-binary-tree-postorder-traversal
    public class Solution145 {
        public IList<int> PostorderTraversalTwoStack(TreeNode root) {
            if (root == null) {
                return [];
            }

            var visitorStack = new Stack<TreeNode>();
            var resultStack = new Stack<int>();

            visitorStack.Push(root);
            while (visitorStack.Count > 0) {
                var curr = visitorStack.Pop();
                resultStack.Push(curr.val);

                if (curr.right != null) {
                    visitorStack.Push(curr.right);
                }
                if (curr.left != null) {
                    visitorStack.Push(curr.left);
                }
            }

            var res = new List<int>();
            while (resultStack.Count > 0) {
                res.Add(resultStack.Pop());
            }

            return res;
        }

        public IList<int> PostorderTraversalOneStack(TreeNode root) {
            if (root == null) {
                return [];
            }

            var stack = new Stack<TreeNode>();
            var res = new List<int>();
            TreeNode prev = null;
            TreeNode curr = root;

            while (curr != null || stack.Count > 0) {
                while (curr != null) {
                    stack.Push(curr);
                    curr = curr.left;
                }

                curr = stack.Pop();
                if (curr.right != null && prev != curr.right) {
                    stack.Push(curr);
                    curr = curr.right;
                } else {
                    res.Add(curr.val);
                    prev = curr;
                    curr = null;
                }
            }

            return res;
        }
    }
}