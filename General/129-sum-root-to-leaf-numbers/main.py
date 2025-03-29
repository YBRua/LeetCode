from typing import Optional, List
from functools import reduce


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# 129-sum-root-to-leaf-numbers
class Solution:
    sum_numbers: int

    def _accumulate(self, vals: List[int]):
        return reduce(lambda x, y: x * 10 + y, vals)

    def _find_sum(self, node: Optional[TreeNode], vals: List[int]):
        vals.append(node.val)

        if node.left is None and node.right is None:
            self.sum_numbers += self._accumulate(vals)
        else:
            if node.left is not None:
                self._find_sum(node.left, vals)
            if node.right is not None:
                self._find_sum(node.right, vals)

        vals.pop()

    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.sum_numbers = 0

        self._find_sum(root, [])

        return self.sum_numbers
