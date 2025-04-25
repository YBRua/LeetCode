using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution142 {
        // 142-linked-list-cycle-ii
        public ListNode DetectCycle(ListNode head) {
            ListNode slow = head, fast = head;
            while (fast != null && fast.next != null && fast.next.next != null) {
                slow = slow.next;
                fast = fast.next.next;

                if (slow == fast) {
                    ListNode pivot = head;
                    while (pivot != slow) {
                        pivot = pivot.next;
                        slow = slow.next;
                    }
                    return pivot;
                }
            }
            return null;
        }
    }
}
