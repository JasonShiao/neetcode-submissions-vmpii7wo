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
    int gcd(int a, int b) {
        int large = a > b ? a : b;
        int small = b >= a ? a : b;
        int r = large % small;
        while (r != 0) {
            int tmp = large;
            large = small;
            small = r;
            r = large % small;
        }
        return small;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;
        ListNode* nxt = head->next;

        while (nxt != nullptr) {
            auto new_node = new ListNode(gcd(cur->val, nxt->val));
            // update links
            cur->next = new_node;
            new_node->next = nxt;
            // update pointer
            cur = nxt;
            nxt = nxt->next;
        }

        return head;
    }
};