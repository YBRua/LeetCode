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

// <https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/discuss/274621/JavaC%2B%2BPython-Iterative-Stack-Solution>
public class Solution {
    public TreeNode RecoverFromPreorder(string s) {
        var traversal = s.ToCharArray();
        int cursor = 0;
        var stack = new Stack<TreeNode>();
        while (cursor < traversal.Length) {
            int level = 0;
            while (traversal[cursor] == '-') {
                level++;
                cursor++;
            }
            int val = 0;
            while (cursor < traversal.Length && traversal[cursor] != '-') {
                val = val * 10 + System.Int32.Parse(traversal[cursor]);
                cursor++;
            }
            
            var node = new TreeNode(val);
            while (stack.Count > level) {
                stack.Pop();
            }
            if (stack.Count > 0) {
                if (stack.Peek().left == null) {
                    stack.Peek().left = node;
                } else {
                    stack.Peek().right = node;
                }
            }
            stack.Push(node);
        }
        return stack.Peek();
    }
}
