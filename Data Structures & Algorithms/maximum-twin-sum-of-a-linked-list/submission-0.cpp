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
    int pairSum(ListNode* head) {
        // Naive solution: O(n) space store values in an array

        // Approach 2: O(1) extra space, reverse the first half of linked list
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            ListNode* tmp = slow->next;
            // reverse the link, override the slow->next
            slow->next = prev;
            // update prev
            prev = slow;
            // update slow (with original slow->next)
            slow = tmp;
        }

        // at this point, slow is at the first node of second half
        // prev is the last node of first half

        int max_val = 0;
        while (prev != nullptr) {
            int tmp_val = prev->val + slow->val;
            if (tmp_val > max_val) {
                max_val = tmp_val;
            }
            // move to next twin nodes
            slow = slow->next;
            prev = prev->next;
        }

        return max_val;
        
    }
};