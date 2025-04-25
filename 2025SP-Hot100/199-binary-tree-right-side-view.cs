using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution199 {
        // 199-binary-tree-right-side-view
        public IList<int> RightSideView(TreeNode root) {
            List<int> view = [];
            Queue<TreeNode> bfsq = [];

            if (root == null) {
                return [];
            }

            bfsq.Enqueue(root);
            while (bfsq.Count > 0) {
                int numNodesInLevel = bfsq.Count;
                for (int i = 0; i < numNodesInLevel; ++i) {
                    var curr = bfsq.Dequeue();
                    if (curr.left != null) {
                        bfsq.Enqueue(curr.left);
                    }
                    if (curr.right != null) {
                        bfsq.Enqueue(curr.right);
                    }

                    if (i == numNodesInLevel - 1) {
                        view.Add(curr.val);
                    }
                }
            }

            return view;
        }
    }
}
