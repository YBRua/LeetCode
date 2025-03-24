from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def _visit(self, node: TreeNode):
        if node is None:
            return (None, None)

        if node.left is None and node.right is None:
            return (node, node)

        left = node.left
        right = node.right

        (left_head, left_end) = self._visit(left)
        (right_head, right_end) = self._visit(right)

        if left_head is not None and right_head is not None:
            left_end.left = None
            left_end.right = right_head
            node.left = None
            node.right = left_head

            return node, right_end

        elif left_head is not None:
            node.left = None
            node.right = left_head
            return node, left_end

        else:
            node.left = None
            node.right = right_head
            return node, right_end

    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None:
            return None

        self._visit(root)
