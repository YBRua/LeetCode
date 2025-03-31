using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution2 {
        // 2-add-two-numbers
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
            ListNode res = new(-1);
            ListNode curr = res;

            int carry = 0;
            while (l1 != null && l2 != null) {
                int sum = l1.val + l2.val + carry;
                if (sum >= 10) {
                    sum %= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                curr.next = new(sum);
                curr = curr.next;
                l1 = l1.next;
                l2 = l2.next;
            }
            while (l1 != null) {
                int sum = l1.val + carry;
                if (sum >= 10) {
                    sum %= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                curr.next = new(sum);
                curr = curr.next;
                l1 = l1.next;
            }
            while (l2 != null) {
                int sum = l2.val + carry;
                if (sum >= 10) {
                    sum %= 10;
                    carry = 1;
                } else {
                    carry = 0;
                }
                curr.next = new(sum);
                curr = curr.next;
                l2 = l2.next;
            }

            if (carry != 0) {
                curr.next = new(1);
            }

            return res.next;
        }
    }
}
