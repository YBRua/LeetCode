from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# 124-binary-tree-maximum-path-sum
class Solution:
    max_sum = 0

    def _visitor(self, node: Optional[TreeNode]):
        if node is None:
            return 0

        left_gain = self._visitor(node.left)
        right_gain = self._visitor(node.right)

        node_sum = node.val + max(left_gain, 0) + max(right_gain, 0)
        self.max_sum = max(self.max_sum, node_sum)

        return node.val + max(max(left_gain, right_gain), 0)

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.max_sum = -float("inf")
        self._visitor(root)

        return self.max_sum
