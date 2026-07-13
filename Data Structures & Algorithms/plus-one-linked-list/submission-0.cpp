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
    ListNode* plusOne(ListNode* head) {
        stack<ListNode*> node_st;
        ListNode* cur = head;
        while (cur != nullptr) {
            node_st.push(cur);
            cur = cur->next;
        }

        // need to handle increasing digit (e.g. 99 -> 100)
        int carry = 1; // add 1 to the right most
        while (!node_st.empty()) {
            cur = node_st.top();
            node_st.pop();
            cur->val += carry;
            carry = (cur->val / 10);
            cur->val %= 10;
        }

        if (carry != 0) {
            // add one digit to the head and update head
            ListNode* new_node = new ListNode{carry, head};
            head = new_node;
        }
        return head;
    }
};
