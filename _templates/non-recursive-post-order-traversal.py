# non-recursive implementation of binary tree post-order traversal
from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        stack: List[TreeNode] = []
        res: List[int] = []

        curr = root
        prev = None
        while curr is not None or len(stack) != 0:
            while curr is not None:
                stack.append(curr)
                curr = curr.left

            curr = stack.pop()

            if curr.right is None or curr.right == prev:
                res.append(curr.val)
                prev = curr
                curr = None
            else:
                stack.append(curr)
                curr = curr.right

        return res
