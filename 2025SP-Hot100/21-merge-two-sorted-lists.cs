using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution21 {
        // 21-merge-two-sorted-lists
        public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
            ListNode dummy = new(-1);
            ListNode curr = dummy;
            while (list1 != null && list2 != null) {
                if (list1.val < list2.val) {
                    curr.next = list1;
                    curr = curr.next;
                    list1 = list1.next;
                } else {
                    curr.next = list2;
                    curr = curr.next;
                    list2 = list2.next;
                }
            }
            while (list1 != null) {
                curr.next = list1;
                curr = curr.next;
                list1 = list1.next;
            }
            while (list2 != null) {
                curr.next = list2;
                curr = curr.next;
                list2 = list2.next;
            }

            return dummy.next;
        }
    }
}
