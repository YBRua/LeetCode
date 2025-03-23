from typing import Optional


# Definition for a Node.
class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


# 138-copy-list-with-random-pointer
class Solution:
    def copyRandomList(self, head: Optional[Node]) -> Optional[Node]:
        new_nodes = dict()

        if head is None:
            return None

        new_head = Node(head.val)

        curr = head.next
        new_curr = new_head

        new_nodes[head] = new_head

        while curr is not None:
            new_node = Node(curr.val)
            new_curr.next = new_node

            new_nodes[curr] = new_node

            new_curr = new_node
            curr = curr.next

        curr = head
        new_curr = new_head

        while curr is not None:
            if curr.random is not None:
                new_curr.random = new_nodes[curr.random]

            curr = curr.next
            new_curr = new_curr.next

        return new_head
