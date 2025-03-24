from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 82-remove-duplicates-from-sorted-list-ii
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return head

        dummy = ListNode(-1, head)
        prev = dummy
        slow = head
        fast = head

        while fast is not None:

            while fast is not None and fast.next is not None and fast.val == fast.next.val:
                fast = fast.next

            if slow != fast:
                # remove from slow to fast
                prev.next = fast.next
                fast = fast.next
                slow = fast
            else:
                # dont remove
                prev = slow
                fast = fast.next
                slow = fast

        return dummy.next
