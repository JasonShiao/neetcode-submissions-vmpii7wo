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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // bruteforce: always compare k vals in each step -> ~O(kn)
        
        // try to optimize: maintain a min heap
        ListNode* cur = nullptr;
        ListNode* root = nullptr;
        typedef std::tuple<int, ListNode*> MyTuple;
        priority_queue<MyTuple, vector<MyTuple>, greater<MyTuple>> min_heap;
        
        for (auto& node: lists) {
            min_heap.push(MyTuple{node->val, node});
        }

        while (min_heap.size() > 0) {
            auto min_node_ptr = get<1>(min_heap.top());
            if (cur == nullptr) {
                cur = min_node_ptr;
                root = cur;
            } else {
                cur->next = min_node_ptr;
                cur = cur->next;
            }
            min_heap.pop();
            // update min heap
            if (min_node_ptr->next != nullptr) {
                min_heap.push(MyTuple{min_node_ptr->next->val, min_node_ptr->next});
            }

        }

        return root;

    }
};
