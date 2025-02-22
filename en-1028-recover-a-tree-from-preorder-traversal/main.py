from collections import deque
from typing import Optional, List, Tuple


class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def _parse_traversal_str(self, traversal: str) -> List[Tuple[int, int]]:
        nodes = []

        p = 0
        while p < len(traversal):
            depth = 0
            while p < len(traversal) and traversal[p] == "-":
                depth += 1
                p += 1

            if traversal[p] != "-":
                # parse next digit
                digit_start = p
                digit_end = p
                while digit_end < len(traversal) and traversal[digit_end].isnumeric():
                    digit_end += 1

                value = int(traversal[digit_start:digit_end])
                p = digit_end

            nodes.append((depth, value))

        return nodes

    def _build_tree(self, seq: deque[Tuple[int, int]]):

        def _runner(current: TreeNode, depth: int):
            if len(seq):
                if seq[0][0] == depth + 1:
                    next = seq.popleft()
                    current.left = TreeNode(next[1])
                    _runner(current.left, depth + 1)

            if len(seq):
                if seq[0][0] == depth + 1:
                    next = seq.popleft()
                    current.right = TreeNode(next[1])
                    _runner(current.right, depth + 1)

        _, root_val = seq.popleft()
        root = TreeNode(root_val)

        _runner(root, 0)

        return root

    def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
        if traversal == "":
            return None

        node_seq = self._parse_traversal_str(traversal)
        print(node_seq)

        root = self._build_tree(deque(node_seq))

        return root


def dfs_tree_print(root: TreeNode):
    res = []

    def _runner(current: TreeNode):
        res.append(current.val)
        if current.left:
            _runner(current.left)
        if current.right:
            _runner(current.right)

    _runner(root)

    return "-".join(str(x) for x in res)


if __name__ == "__main__":
    s1 = "1-401--349---90--88"
    res = Solution().recoverFromPreorder(s1)
    print(dfs_tree_print(res))
