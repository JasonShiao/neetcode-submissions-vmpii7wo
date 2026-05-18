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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // need to store the node before and after the segment
        ListNode* cur = head;
        ListNode* seg_tail; // tail of reversed seg (i.e. origin left)
        ListNode* seg_head; // head of reversed seg (i.e. origin right)
        ListNode* before_seg = nullptr; 
        ListNode* after_seg = nullptr;
        ListNode* prev = nullptr;
        int i = 1;
        // special case: left == right
        if (left == right) {
            return head;
        }

        while (i <= right) {
            if (i == left) {
                // store the pointers
                before_seg = prev;
                seg_tail = cur;
                // not reverse link -> simply move cur and prev
                prev = cur;
                cur = cur->next;
            } else if (i == right) {
                // store the pointers
                if (cur != nullptr) {
                    after_seg = cur->next;
                }
                seg_head = cur;
                // reverse the link
                cur->next = prev;
                // connect after and before seg
                if (before_seg != nullptr) {
                    before_seg->next = seg_head;
                }
                seg_tail->next = after_seg;
                break;
            } else if (i > left) { // reverse the link
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur; // the old cur
                cur = tmp;  // updated cur
            } else if (i < left) {  // i < left, not reverse
                prev = cur;
                cur = cur->next;
            }
            i += 1;
        }

        if (before_seg == nullptr) { // head changed
            return seg_head;
        } else {
            return head;
        }
        
    }
};