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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-5001);

        ListNode* sorted_cur = dummy;
        ListNode* cur = head;
        // O(n^2)
        while (cur != nullptr) {
            ListNode* old_next = cur->next;

            // Find the location and insert
            ListNode* sorted_prev = nullptr;
            sorted_cur = dummy;
            while (sorted_cur != nullptr) {
                if (sorted_cur->val < cur->val) {
                    sorted_prev = sorted_cur;
                    sorted_cur = sorted_cur->next;
                } else {
                    // found the insertion location
                    // insert by modifying 2 links
                    sorted_prev->next = cur;
                    cur->next = sorted_cur;
                    // inserted -> break
                    break;
                }
            }
            // If larger than all in the current sorted
            if (sorted_cur == nullptr) {
                sorted_prev->next = cur;
                cur->next = nullptr;
            }

            cur = old_next;
        }

        return dummy->next;
    }
};