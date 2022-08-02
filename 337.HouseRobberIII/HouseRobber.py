# Definition for a binary tree node.
from typing import Optional, Tuple


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        vals = self._rob_wrapper(root)
        return max(vals[0], vals[1])

    def _rob_wrapper(self, root: TreeNode) -> Tuple[int, int]:
        if root is None:
            return (0, 0)  # children_val, grandchildren_val
        left = self._rob_wrapper(root.left)
        right = self._rob_wrapper(root.right)

        rob_current = left[1] + right[1] + root.val
        leave_current = left[0] + right[0]

        # curernt_val = max(rob_current, dont_rob_current)
        current_val = max(rob_current, leave_current)
        return (current_val, left[0] + right[0])
