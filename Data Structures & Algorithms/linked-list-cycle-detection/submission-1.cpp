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
        // (Intuitive) Approach 1: hash table with ListNode addr as key
        // require extra space O(n)
        // unordered_map<ListNode*, bool> lookup;
        // ListNode* cur = head;
        // while (cur != nullptr) {
        //     if (lookup.find(cur) != lookup.end()) {
        //         return true;
        //     }
        //     lookup[cur] = true;
        //     cur = cur->next;
        // }

        // Approach 2: fast and slow pointer
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        while (fast_ptr != nullptr) {
            fast_ptr = fast_ptr->next;
            if (fast_ptr == nullptr) {
                break; 
            }
            fast_ptr = fast_ptr->next;
            slow_ptr = slow_ptr->next;
            if (fast_ptr == slow_ptr) {
                return true;
            }
        }

        return false;
    }
};
