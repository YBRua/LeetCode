from typing import List, Dict, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# 106-construct-binary-tree-from-inorder-and-postorder-traversal
class Solution:
    def _tom_the_tree_builder(
        self,
        inorder: List[int],
        il: int,
        ir: int,
        memo: Dict[int, int],
        postorder: List[int],
        pl: int,
        pr: int,
    ):
        if not len(postorder):
            return None

        if pl >= pr:
            return None

        if il >= ir:
            return None

        curr_id = postorder[pr - 1]
        curr_node = TreeNode(curr_id)

        split = memo[curr_id]
        left_size = split - il
        right_size = ir - split - 1

        curr_node.left = self._tom_the_tree_builder(
            inorder, il, split, memo, postorder, pl, pl + left_size
        )
        curr_node.right = self._tom_the_tree_builder(
            inorder, split + 1, ir, memo, postorder, pl + left_size, pl + left_size + right_size
        )

        return curr_node

    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # build node_id-to-inorder_idx mapping
        memo = dict()
        for idx, node_id in enumerate(inorder):
            memo[node_id] = idx

        return self._tom_the_tree_builder(
            inorder, 0, len(inorder), memo, postorder, 0, len(postorder)
        )
