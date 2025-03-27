using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 102-binary-tree-level-order-traversal
    public class Solution102 {
        public IList<IList<int>> LevelOrder(TreeNode root) {
            if (root == null) {
                return [];
            }

            List<List<int>> res = [];
            LinkedList<TreeNode> q = new([root]);

            while (q.Count > 0) {
                int size = q.Count;
                List<int> levelRes = [];
                for (int i = 0; i < size; ++i) {
                    var curr = q.First();
                    q.RemoveFirst();

                    levelRes.Add(curr.val);

                    if (curr.left != null) {
                        q.AddLast(curr.left);
                    }
                    if (curr.right != null) {
                        q.AddLast(curr.right);
                    }
                }
                res.Add(levelRes);
            }

            return [.. res];
        }
    }
}