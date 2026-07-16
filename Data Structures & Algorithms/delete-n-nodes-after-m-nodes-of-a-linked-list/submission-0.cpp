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

class Solution {
public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        // Operation period: m + n

        int i = 0;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;
        while (cur != nullptr) {
            if ((i % (m + n)) < m) {
                // keep
                prev = cur;
                cur = cur->next;
            } else {
                // remove
                prev->next = cur->next;
                cur = cur->next;
            }
            i += 1;
        }

        return dummy->next;
    }
};
