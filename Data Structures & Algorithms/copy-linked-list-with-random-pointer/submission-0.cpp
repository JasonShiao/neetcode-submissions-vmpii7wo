/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create a lookup map from origin ListNode* to copied ListNode*
        Node* origin_cur = head;
        Node dummy(0);
        Node* copied_cur = &dummy;
        // First round:
        //   allocate node and build the next links
        //   create lookup table
        unordered_map<Node*, Node*> node_copy_map;
        while (origin_cur != nullptr) {
            Node* new_node = new Node(origin_cur->val);
            copied_cur->next = new_node;
            //
            node_copy_map[origin_cur] = new_node;

            origin_cur = origin_cur->next;
            copied_cur = copied_cur->next;
        }
        // Second round:
        //   link the random ptr
        origin_cur = head;
        copied_cur = dummy.next;
        while (origin_cur != nullptr) {
            if (origin_cur->random != nullptr) {
                copied_cur->random = node_copy_map[origin_cur->random];
            }
            copied_cur = copied_cur->next;
            origin_cur = origin_cur->next;
        }

        return dummy.next;
    }
};
