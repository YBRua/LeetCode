namespace Hot100SU2025 {


    // 206-reverse-linked-list
    public class Solution206 {
        public ListNode ReverseList(ListNode head) {
            ListNode prev = null;
            ListNode curr = head;

            while (curr != null) {
                ListNode next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }

            return prev;
        }
    }
}