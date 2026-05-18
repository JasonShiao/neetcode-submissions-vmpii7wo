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
        // slow is move with fast when dist(fast, slow) == (n - 1)

        // Tips: Use a dummy node to handle remove from edge (start)
        ListNode dummy(0, head);

        int ptr_dist = 0;
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        ListNode* prev = &dummy;
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
        prev->next = slow_ptr->next;

        return dummy.next;

    }
};
