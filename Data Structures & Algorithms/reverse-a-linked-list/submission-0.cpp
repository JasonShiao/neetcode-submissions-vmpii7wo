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
    ListNode* reverseList(ListNode* head) {
        // iterate from head to end, keep move the node to front (as new head)     
        if (head == nullptr) {
            return head;
        }
        ListNode* curr = head->next;
        ListNode* prev = head;
        while (curr != nullptr) {
            // update prev
            if (prev != nullptr) {
                prev->next = curr->next;
            }
            // update curr (become head and update next)
            ListNode* temp_next = curr->next; // Don't forget to store old next
            curr->next = head;
            head = curr;

            curr = temp_next;
        }

        return head;
    }
};
