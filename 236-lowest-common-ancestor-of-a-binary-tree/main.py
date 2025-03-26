# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


# 236-lowest-common-ancestor-of-a-binary-tree
class Solution:
    def _find(self, node: "TreeNode", p: "TreeNode", q: "TreeNode"):
        if node is None:
            return None

        if node.val == p.val:
            return p
        elif node.val == q.val:
            return q

        left = self._find(node.left, p, q)
        right = self._find(node.right, p, q)

        if left is not None and right is not None:
            return node
        if left is not None:
            return left
        if right is not None:
            return right

        return None

    def lowestCommonAncestor(self, root: "TreeNode", p: "TreeNode", q: "TreeNode") -> "TreeNode":
        return self._find(root, p, q)
