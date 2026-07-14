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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        // 1. scan once to get the duplicate num
        unordered_map<int, int> val_cnt;
        ListNode* cur = head;
        while (cur != nullptr) {
            val_cnt[cur->val] += 1;
            cur = cur->next;
        }

        // 2. remove
        // Add a dummy for convenience
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* prev = dummy;
        cur = head;
        while (cur != nullptr) {
            ListNode* old_next = cur->next;

            if (val_cnt[cur->val] >= 2) {
                // update prev->next only
                prev->next = old_next;
            } else {
                // update prev only
                prev = cur;
            }

            cur = old_next;
        }

        return dummy->next;
    }
};
