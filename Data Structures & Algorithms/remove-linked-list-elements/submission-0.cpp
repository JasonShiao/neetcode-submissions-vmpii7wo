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
    ListNode* removeElements(ListNode* head, int val) {
        // 1. Add a dummy for convenience
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* cur = head;
        while (cur != nullptr) {
            // Remember to update prev pointer!!!!
            if (cur->val == val) {
                // remove cur and keep prev
                prev->next = cur->next;
                cur = cur->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        return dummy->next;
    }
};