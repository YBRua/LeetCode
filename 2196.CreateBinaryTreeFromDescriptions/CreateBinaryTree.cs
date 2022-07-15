using System;
using System.Collections.Generic;

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    public TreeNode CreateBinaryTree(int[][] descriptions) {
        var existingNodes = new Dictionary<int, TreeNode>();
        var child2parent = new Dictionary<int, int>();
        foreach (int[] desc in descriptions) {
            int parent = desc[0];
            int child = desc[1];
            bool isLeft = desc[2] == 1;
            TreeNode parentNode;
            TreeNode childNode;
            if (!existingNodes.ContainsKey(parent)) {
                existingNodes.Add(parent, new TreeNode(parent));
            }
            parentNode = existingNodes[parent];
            if (!existingNodes.ContainsKey(child)) {
                existingNodes.Add(child, new TreeNode(child));
            }
            childNode = existingNodes[child];

            if (isLeft) {
                parentNode.left = childNode;
            } else {
                parentNode.right = childNode;
            }
            child2parent.Add(child, parent);
        }

        if (descriptions.Length == 0) {
            return null;
        }
        int current = descriptions[0][0];
        while (child2parent.ContainsKey(current)) {
            current = child2parent[current];
        }

        return existingNodes[current];
    }
}
