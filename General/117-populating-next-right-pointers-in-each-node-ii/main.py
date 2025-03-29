# Definition for a Node.
class Node:
    def __init__(
        self, val: int = 0, left: "Node" = None, right: "Node" = None, next: "Node" = None
    ):
        self.val = val
        self.left = left
        self.right = right
        self.next = next


# 117-populating-next-right-pointers-in-each-node-ii
# each layer forms a linked list
# so at layer i, we can connect nodes in layer i+1
# then move to the next layer
class Solution:
    def connect(self, root: "Node") -> "Node":
        curr = root
        while curr:
            # dummy node for tracking the head of next level
            next = dummy = Node()

            while curr:
                if curr.left:
                    next.next = curr.left
                    next = curr.left
                if curr.right:
                    next.next = curr.right
                    next = curr.right

                # note that layer i is also a linked list
                # which is processed at layer i-1
                curr = curr.next

            curr = dummy.next

        return root
