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
        // Trivial but must be careful!! error prone!!

        // use 2 stacks
        // 1. Fill 2 stacks
        stack<ListNode*> st1;
        stack<ListNode*> st2;
        ListNode* cur = l1;
        while (cur != nullptr) {
            st1.push(cur);
            cur = cur->next;
        }
        cur = l2;
        while (cur != nullptr) {
            st2.push(cur);
            cur = cur->next;
        }

        // 2. Pop and update (store to list 1)
        ListNode* prev = nullptr;
        int carry = 0;
        while (!st1.empty() || !st2.empty()) {
            if (st1.empty()) {
                auto node2 = st2.top(); st2.pop();
                int sum_res = node2->val + carry;
                carry = sum_res / 10;
                node2->val = sum_res % 10;
                // save to l2's node
                node2->next = prev;
                // prev is l2's node
                prev = node2;
            } else if (st2.empty()) {
                auto node1 = st1.top(); st1.pop();
                int sum_res = node1->val + carry;
                carry = sum_res / 10;
                // save to l1's node
                node1->val = sum_res % 10;
                node1->next = prev;
                prev = node1;
            } else {
                auto node1 = st1.top(); st1.pop();
                auto node2 = st2.top(); st2.pop();
                int sum_res = node1->val + node2->val + carry;
                carry = sum_res / 10;
                // save to l1's node
                node1->val = sum_res % 10;
                
                node1->next = prev;
                prev = node1;
            }
        }

        if (carry) {
            ListNode* new_node = new ListNode(carry, prev);
            prev = new_node;
        }

        return prev;
    }
};