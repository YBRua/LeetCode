from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# 1123-lowest-common-ancestor-of-deepest-leaves
class Solution:
    def lcaDeepestLeaves(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def _postorder_visitor(node: TreeNode):
            if node is None:
                return 0, None

            ldepth, llca = _postorder_visitor(node.left)
            rdepth, rlca = _postorder_visitor(node.right)

            if ldepth > rdepth:
                return ldepth + 1, llca
            if rdepth > ldepth:
                return rdepth + 1, rlca
            return ldepth + 1, node

        depth, res = _postorder_visitor(root)

        return res
