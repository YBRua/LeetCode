namespace Hot100SU2025 {
    // 234-palindrome-linked-list
    public class Solution234 {
        private ListNode frontPointer;

        public bool RecursiveCheck(ListNode current) {
            if (current != null) {
                if (!RecursiveCheck(current.next)) {
                    return false;
                }
                if (frontPointer.val != current.val) {
                    return false;
                }
                frontPointer = frontPointer.next;
            }

            return true;
        }

        public bool IsPalindrome(ListNode head) {
            frontPointer = head;
            return RecursiveCheck(head);
        }
    }
}