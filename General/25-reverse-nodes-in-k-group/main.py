from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def _reverse_segment(self, begin: ListNode, end: ListNode):
        prev = None
        curr = begin
        while curr is not None and curr != end:
            # prev .. curr -> next
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next

        return (prev, begin)

    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(-1, head)
        slow = head
        fast = head

        prev = dummy
        while fast is not None:

            for _ in range(k):
                if fast is None:
                    return dummy.next
                fast = fast.next

            new_begin, new_end = self._reverse_segment(slow, fast)
            prev.next = new_begin
            new_end.next = fast

            prev = new_end
            slow = fast

        return dummy.next
