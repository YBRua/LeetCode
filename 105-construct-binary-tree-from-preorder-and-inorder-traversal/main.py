from typing import List, Optional
from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# 105-construct-binary-tree-from-preorder-and-inorder-traversal
class Solution:
    def _tom_the_tree_builder(
        self,
        preorder: deque[int],
        inorder: List[int],
        left: int,
        right: int,
    ):
        if not len(preorder):
            return None

        if left >= right:
            return None

        curr_val = preorder.popleft()
        curr_node = TreeNode(curr_val)

        ptr = left
        while ptr < right:
            if inorder[ptr] == curr_val:
                break
            ptr += 1

        curr_node.left = self._tom_the_tree_builder(preorder, inorder, left, ptr)
        curr_node.right = self._tom_the_tree_builder(preorder, inorder, ptr + 1, right)

        return curr_node

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        return self._tom_the_tree_builder(deque(preorder), inorder, 0, len(preorder))
