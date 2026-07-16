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
    bool isPalindrome(ListNode* head) {
        // 1. find the mid -> Common pattern
        // tips: fast & slow pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // Now, slow is at the middle or the first of the second half!!

        // 2. Reverse the second half!! (changed the list!)
        // tips: Common pattern of reverse linked list!
        //       keep moving node to the head
        ListNode* rev_head = nullptr; // NOTICE: this is critical!!!
        // rev_head also be called as prev in most code!
        // by rev_head = nullptr, the first node's next will become nullptr!
        ListNode* cur = slow;
        while (cur != nullptr) {
            ListNode* old_next = cur->next;

            cur->next = rev_head; 
            rev_head = cur;

            cur = old_next;
        }

        // 3. Compare
        ListNode* ptr1 = head;
        ListNode* ptr2 = rev_head;
        while (ptr1 != slow) {
            if (ptr1->val != ptr2->val) {
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return true;

    }
};