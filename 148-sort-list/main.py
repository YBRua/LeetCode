from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def _merge_sort(self, start: ListNode):
        if start is None or start.next is None:
            return start

        slow = start
        fast = start.next
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next

        split = slow.next
        slow.next = None

        left = self._merge_sort(start)
        right = self._merge_sort(split)

        res = ListNode()
        head = res
        while left is not None and right is not None:
            if left.val < right.val:
                res.next = left
                left = left.next
            else:
                res.next = right
                right = right.next
            res = res.next

        if left is not None:
            res.next = left
        else:
            res.next = right

        return head.next

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self._merge_sort(head)
