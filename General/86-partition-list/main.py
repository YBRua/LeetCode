from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# 86-partition-list
class Solution:
    def _append(self, ptr: ListNode, next: ListNode):
        ptr.next = next
        while ptr.next is not None:
            ptr = ptr.next

    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        lts = ListNode(-1)
        lt_ptr = lts
        gts = ListNode(-1)
        gt_ptr = gts
        eqs = ListNode(-1)
        eq_ptr = eqs

        node = head
        while node is not None:
            if node.val < x:
                self._append(lt_ptr, node)
            elif node.val > x:
                self._append(gt_ptr, node)
            else:
                self._append(eq_ptr, node)

        self._append(lt_ptr, eqs.next)
        self._append(lt_ptr, gts.next)

        return lt_ptr.next
