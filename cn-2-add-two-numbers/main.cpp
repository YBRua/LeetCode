struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr_p = head;

        ListNode *p1 = l1, *p2 = l2;

        int carry = 0;
        while (p1 != nullptr && p2 != nullptr) {
            int sum = p1->val + p2->val + carry;
            carry = 0;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            ListNode* res = new ListNode(sum);
            curr_p->next = res;
            curr_p = res;

            p1 = p1->next;
            p2 = p2->next;
        }
        while (p1 != nullptr) {
            int sum = p1->val + carry;
            carry = 0;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            ListNode* res = new ListNode(sum);
            curr_p->next = res;
            curr_p = res;

            p1 = p1->next;
        }
        while (p2 != nullptr) {
            int sum = p2->val + carry;
            carry = 0;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            }
            ListNode* res = new ListNode(sum);
            curr_p->next = res;
            curr_p = res;

            p2 = p2->next;
        }

        if (carry != 0) {
            ListNode* carry_node = new ListNode(1);
            curr_p -> next = carry_node;
        }

        return head->next;
    }
};
