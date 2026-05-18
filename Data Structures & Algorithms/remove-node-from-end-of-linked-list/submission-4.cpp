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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // use slow and fast pointer
        // slow is move with fast when fast - slow = (n - 1)
        int ptr_dist = 0;
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        ListNode* prev = nullptr;
        while (fast_ptr->next != nullptr) {
            if (ptr_dist < (n-1)) {
                // move fast ptr only
                fast_ptr = fast_ptr->next;
                ptr_dist += 1;
            } else { // == n-1
                // move both
                prev = slow_ptr;
                slow_ptr = slow_ptr->next;
                fast_ptr = fast_ptr->next;
            }
        }

        // remove the slow_ptr node
        if (prev != nullptr) { // not at the start
            prev->next = slow_ptr->next;
            delete slow_ptr;
            slow_ptr = nullptr;
            return head;
        } else { // remove the head
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }

    }
};
