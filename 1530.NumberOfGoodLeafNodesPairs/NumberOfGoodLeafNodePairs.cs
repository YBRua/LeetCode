using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    private int _count;
    public List<int> _countNodes(TreeNode root, int dist) {
        if (root.left == null && root.right == null) {
            // for leaf node we return empty lists
            return new List<int>();
        }
        List<int> left = new List<int>(), right = new List<int>();
        if (root.left != null) {
            left = _countNodes(root.left, dist);
            if (left.Count == 0) {
                // empty list: a leaf node
                left.Add(1);
            }
        }
        if (root.right != null) {
            right = _countNodes(root.right, dist);
            if (right.Count == 0) {
                right.Add(1);
            }
        }

        // update _count
        foreach (var l in left) {
            foreach (var r in right) {
                if (l + r <= dist) {
                    ++_count;
                }
            }
        }

        // update and merge left and right
        for (int i = 0; i < left.Count; ++i) {
            left[i] += 1;
        }
        foreach (var r in right) {
            left.Add(r + 1);
        }
        return left;
    }
    public int CountPairs(TreeNode root, int distance) {
        _count = 0;
        _countNodes(root, distance);
        return _count;
    }
}
