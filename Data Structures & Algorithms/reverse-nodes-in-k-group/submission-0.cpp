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
    ListNode* reverseLinkedList(ListNode* prev_tail, ListNode* cur_tail) {
        // Reverse of Singly linked-list

        // from head -> pick one and insert to the tail (tail ptr remain not change)
        ListNode* new_cur_tail = prev_tail->next;
        ListNode* pivot = cur_tail; // always insert right after it
        ListNode* cursor = prev_tail->next;
        while (cursor != pivot) {
            // break 2 links
            ListNode* next_cursor = cursor->next;
            ListNode* tmp = pivot->next;
            // link the 2nd part
            pivot->next = cursor;
            cursor->next = tmp; // old pivot next
            // link the 1st part
            cursor = next_cursor;
            prev_tail->next = cursor;
        }

        // Critical: must return the updated tail cursor
        return new_cur_tail;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // add a temporary dummy head
        ListNode dummy;
        ListNode* dummy_ptr = &dummy;
        dummy_ptr->next = head;
        ListNode* prev_tail = dummy_ptr;
        ListNode* cur_tail = dummy_ptr;
        int idx = 0;
        while (cur_tail != nullptr) {
            if ((idx > 0) && (idx % k == 0)) {
                // must update new prev_tail
                prev_tail = reverseLinkedList(prev_tail, cur_tail);
                // must update new cur_tail
                cur_tail = prev_tail;
            }
            cur_tail = cur_tail->next;
            idx += 1;
        }

        return dummy_ptr->next;
    }
};
