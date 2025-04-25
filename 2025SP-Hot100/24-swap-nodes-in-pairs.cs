using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution24 {
        // 24-swap-nodes-in-pairs
        public ListNode SwapPairs(ListNode head) {
            if (head == null) { return null; }

            var dummy = new ListNode(-1) {
                next = head
            };

            var prev = dummy;
            var curr = head;

            while (curr != null && curr.next != null) {
                var next = curr.next;
                var futr = next.next;
                prev.next = next;
                next.next = curr;
                curr.next = futr;

                prev = curr;  // curr and prev has been swapped so curr is now prev of futr
                curr = futr;
            }

            return dummy.next;
        }
    }
}
