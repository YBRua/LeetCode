#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    pair<ListNode*, ListNode*> _reverse_section(ListNode* head, ListNode* end) {
        ListNode* current = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (current != end) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return {prev, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* sec_start = head;
        ListNode* sec_end = sec_start;
        ListNode* prev = dummy;

        while (sec_start) {
            for (int i = 0; i < k; ++i) {
                if (!sec_end) return dummy->next;
                sec_end = sec_end->next;
            }
            auto head_tail = _reverse_section(sec_start, sec_end);
            prev->next = head_tail.first;
            head_tail.second->next = sec_end;
            sec_start = sec_end;
            prev = head_tail.second;
        }

        return dummy->next;
    }
};
