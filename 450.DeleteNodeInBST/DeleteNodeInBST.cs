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
    private TreeNode _findMinVal(TreeNode root) {
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }
    public TreeNode DeleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        } else if (key < root.val) {
            // delete in left subtree
            root.left = DeleteNode(root.left, key);
        } else if (key > root.val) {
            // delete in right subtree
            root.right = DeleteNode(root.right, key);
        } else {
            // delete current node
            // replace with min node in right subtree
            // and delete min node
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            }
            TreeNode minNode = _findMinVal(root.right);
            root.val = minNode.val;
            root.right = DeleteNode(root.right, root.val);
        }
        return root;

    }
}
