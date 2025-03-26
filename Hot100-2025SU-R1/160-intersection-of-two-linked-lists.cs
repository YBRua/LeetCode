using System;
using System.Collections.Generic;
using System.Linq;


namespace Hot100SU2025 {
    // 160-intersection-of-two-linked-lists
    public class Solution160 {
        public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
            if (headA == null || headB == null) {
                return null;
            }

            ListNode ptrA = headA;
            ListNode ptrB = headB;

            while (ptrA != ptrB) {
                ptrA = ptrA == null ? headB : ptrA.next;
                ptrB = ptrB == null ? headA : ptrB.next;
            }

            return ptrA;
        }
    }
}