public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    private TreeNode _traverse(TreeNode current, TreeNode p, TreeNode q) {
        if (current == null || current.val == p.val || current.val == q.val) {
            return current;
        }

        TreeNode left = _traverse(current.left, p, q);
        TreeNode right = _traverse(current.right, p ,q);

        if (left != null && right != null) {
            return current;
        } else {
            return left ?? right;
        }
    }
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return _traverse(root, p, q);
    }
}
