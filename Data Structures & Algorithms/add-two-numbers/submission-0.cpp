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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* root = nullptr;
        ListNode* res_cur = root;
        while (cur1 != nullptr || cur2 != nullptr) {
            // sum of digit from two numbers and carry
            int temp = 0;
            if (cur1 != nullptr) {
                temp += cur1->val;
                cur1 = cur1->next;
            }
            if (cur2 != nullptr) {
                temp += cur2->val;
                cur2 = cur2->next;
            }
            temp += carry;

            // handle the first node
            if (root == nullptr) {
                root = new ListNode(temp % 10);
                carry = temp / 10;
                res_cur = root;
                continue;
            }

            // compute current node's val and carry
            res_cur->next = new ListNode(temp % 10);
            carry = temp / 10;
            
            // update res cursor
            res_cur = res_cur->next;
        }

        if (carry) {
            res_cur->next = new ListNode(carry);
            res_cur = res_cur->next;
        }

        return root;
    }
};
