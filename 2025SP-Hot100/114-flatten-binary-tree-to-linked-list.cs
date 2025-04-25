using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution114 {
        // 114-flatten-binary-tree-to-linked-list.cs
        public (TreeNode, TreeNode) FlattenImpl(TreeNode root) {
            if (root == null) {
                return (null, null);
            }

            if (root.left == null && root.right == null) {
                return (root, root);
            }

            (var leftStart, var leftEnd) = FlattenImpl(root.left);
            (var rightStart, var rightEnd) = FlattenImpl(root.right);

            if (leftStart != null && rightStart != null) {
                leftEnd.left = null;
                leftEnd.right = rightStart;
                root.left = null;
                root.right = leftStart;
                return (root, rightEnd);
            } else if (leftStart != null) {
                root.left = null;
                root.right = leftStart;
                return (root, leftEnd);
            } else {
                root.left = null;
                root.right = rightStart;
                return (root, rightEnd);
            }
        }

        public void Flatten(TreeNode root) {
            FlattenImpl(root);
        }
    }
}
