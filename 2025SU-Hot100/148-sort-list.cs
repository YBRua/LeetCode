using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution148 {
        // 148-sort-list
        private ListNode MergeSort(ListNode start) {
            if (start == null || start.next == null) {
                return start;
            }

            ListNode slow = start;
            ListNode fast = start.next;

            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
            }

            var split = slow.next;
            slow.next = null;

            var left = MergeSort(start);
            var right = MergeSort(split);

            var res = new ListNode(-1);
            var curr = res;

            while (left != null && right != null) {
                if (left.val < right.val) {
                    curr.next = left;
                    left = left.next;

                } else {
                    curr.next = right;
                    right = right.next;
                }
                curr = curr.next;
                curr.next = null;
            }

            if (left != null) {
                curr.next = left;
            } else {
                curr.next = right;
            }

            return res.next;
        }

        public ListNode SortList(ListNode head) {
            return MergeSort(head);
        }
    }
}
