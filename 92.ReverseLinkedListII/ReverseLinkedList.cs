public class ListNode {
    public int val;
    public ListNode next;
    public ListNode(int val=0, ListNode next=null) {
        this.val = val;
        this.next = next;
    }
}

public class Solution {
    public ListNode ReverseBetween(ListNode head, int left, int right) {
        if (head == null) {
            return null;
        }
        var dummy = new ListNode(-1, head);
        var secBegin = dummy;
        for (int i = 0; i < left - 1; ++i) {
            secBegin = secBegin.next;
        }

        ListNode current = secBegin.next;
        ListNode prev = null;
        ListNode next = null;
        for (int i = 0; i < right - left + 1; ++i) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        secBegin.next.next = next;
        secBegin.next = prev;

        return dummy.next;
    }
}
