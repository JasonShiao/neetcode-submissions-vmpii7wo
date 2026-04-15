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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = nullptr;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;
        if (list1 == nullptr && list2 == nullptr) {
            return head;
        } else if (list1 == nullptr) {
            head = cur2;
            cur2 = cur2->next;
        } else if (list2 == nullptr) {
            head = cur1;
            cur1 = cur1->next;
        } else {
            if (list1->val < list2->val) {
                head = cur1;
                cur1 = cur1->next;
            } else {
                head = cur2;
                cur2 = cur2->next;
            }
        }
        ListNode* tail = head;

        while (cur1 != nullptr || cur2 != nullptr) {
            if (cur1 == nullptr) {
                tail->next = cur2; // update tail node's next link
                tail = cur2; // move tail ptr
                cur2 = cur2->next; // move cur2 ptr
            } else if (cur2 == nullptr) {
                tail->next = cur1;
                tail = cur1;
                cur1 = cur1->next;
            } else {
                if (cur1->val < cur2->val) {
                    tail->next = cur1;
                    tail = cur1;
                    cur1 = cur1->next;
                } else {
                    tail->next = cur2;
                    tail = cur2;
                    cur2 = cur2->next;
                }
            }
        }

        return head;
    }
};
