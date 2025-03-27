from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 92-reverse-linked-list-ii
class Solution:
    # single-scan method, promote curr to the beginning of the reverse section
    # e.g., [1, 2, 3, 4, 5], left=2, right=4
    # -> [1, 3, 2, 4, 5] -> [1, 4, 3, 2, 5]
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head:
            return None

        dummy = ListNode(-1, head)
        lbound = dummy

        for _ in range(left - 1):
            lbound = lbound.next

        curr = lbound.next
        for _ in range(right - left):
            next = curr.next
            curr.next = next.next
            next.next = lbound.next
            lbound.next = next

        return dummy.next
