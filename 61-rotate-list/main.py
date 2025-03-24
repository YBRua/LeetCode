from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 61-rotate-list
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        # compute length
        n = 0
        ptr = head
        while ptr is not None:
            n += 1
            ptr = ptr.next

        if n == 0:
            return None

        k = k % n

        if k == 0:
            return head

        dummy = ListNode(-1, head)
        slow = dummy
        fast = dummy

        for _ in range(k):
            fast = fast.next

        while fast.next is not None:
            fast = fast.next
            slow = slow.next

        new_head = slow.next
        new_end = fast

        slow.next = None
        new_end.next = dummy.next

        return new_head
