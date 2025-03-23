from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 21-merge-two-sorted-lists
class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        p1 = list1
        p2 = list2

        head = ListNode()
        curr = head

        while p1 is not None and p2 is not None:
            if p1.val < p2.val:
                curr.next = p1
                p1 = p1.next
            else:
                curr.next = p2
                p2 = p2.next

            curr = curr.next

        while p1 is not None:
            curr.next = p1
            p1 = p1.next
            curr = curr.next

        while p2 is not None:
            curr.next = p2
            p2 = p2.next
            curr = curr.next

        return head.next
