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
    ListNode* rotateRight(ListNode* head, int k) {
        // 1. get length of list first -> use to mod k
        ListNode* cur = head;
        ListNode* tail = nullptr;
        int length = 0;
        while (cur != nullptr) {
            length += 1;
            tail = cur;
            cur = cur->next;
        }
        // NOTICE: handle special case!!
        if (length == 0) {
            return head;
        }

        // separate into two lists and connect
        ListNode* front_head = nullptr;
        ListNode* back_tail = nullptr;
        // length - k_mod -> idx of break
        cur = head;
        int i = 0;
        int k_mod = k % length;
         // NOTICE: handle special case!!
        if (k_mod == 0) {
            return head; // not shifting
        }
        while (cur != nullptr) {
            if (i == (length - k_mod - 1)) {
                break;
            }
            cur = cur->next;
            i += 1;
        }
        front_head = cur->next;
        back_tail = cur;
        back_tail->next = nullptr;
        tail->next = head; // head will always be the head of second part
        // tail will always be the tail of first part

        return front_head;
    }
};