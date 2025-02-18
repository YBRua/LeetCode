#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    pair<ListNode*, ListNode*> _reverseSection(ListNode* sec_start, ListNode* sec_end) {
        ListNode *prev = nullptr, *curr = sec_start, *next = nullptr;
        while (curr != sec_end) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // section endpoints (new_head, new_tail)
        return {prev, sec_start};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* sec_start = head;
        ListNode* sec_end = sec_start;
        ListNode* prev = dummy;

        while (sec_start) {
            for (int i = 0; i < k; ++i) {
                if (!sec_end) {
                    return dummy->next;
                }
                sec_end = sec_end->next;
            }
            auto sec_endpoints = _reverseSection(sec_start, sec_end);
            prev->next = sec_endpoints.first;
            sec_endpoints.second->next = sec_end;

            sec_start = sec_end;
            prev = sec_endpoints.second;
        }

        return dummy->next;
    }
};
