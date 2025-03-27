using System.Collections.Generic;

namespace Hot100SU2025 {
    // 230-kth-smallest-element-in-a-bst
    public class Solution230 {

        public int KthSmallest(TreeNode root, int k) {
            List<TreeNode> stack = [];
            while (root != null || stack.Count > 0) {
                while (root != null) {
                    stack.Add(root);
                    root = root.left;
                }

                root = stack[^1];
                stack.RemoveAt(stack.Count - 1);

                k -= 1;
                if (k == 0) {
                    return root.val;
                }

                root = root.right;
            }

            return -1;
        }
    }
}