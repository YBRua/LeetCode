using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution19 {
        // 19-remove-nth-node-from-end-of-list
        public ListNode RemoveNthFromEnd(ListNode head, int n) {
            ListNode dummy = new ListNode(-1);
            dummy.next = head;

            ListNode slow = dummy;
            ListNode fast = head;

            for (int i = 0; i < n; ++i) {
                fast = fast.next;
            }

            while (fast != null) {
                fast = fast.next;
                slow = slow.next;
            }

            // here slow points to prev
            var prev = slow;
            var curr = slow.next;
            var next = curr.next;

            curr.next = null;
            prev.next = next;

            return dummy.next;
        }
    }
}
