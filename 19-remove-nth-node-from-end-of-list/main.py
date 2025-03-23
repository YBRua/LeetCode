from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        if head is None:
            return None

        dummy = ListNode(-1, head)

        fast = head
        slow = head
        prev = dummy

        for _ in range(n):
            fast = fast.next

        while fast is not None:
            prev = slow
            fast = fast.next
            slow = slow.next

        prev.next = slow.next
        slow.next = None

        return dummy.next
