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
    bool hasCycle(ListNode* head) {
        // hash table for listNode addr
        unordered_map<ListNode*, bool> lookup;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (lookup.find(cur) != lookup.end()) {
                return true;
            }
            lookup[cur] = true;
            cur = cur->next;
        }

        return false;
    }
};
