/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // BFS from right to left
        // maintain the current layer and prev Node
        deque<pair<Node*, int>> dq;
        if (root == nullptr) {
            return root;
        }

        int current_layer = -1;
        Node* prev_node = nullptr;
        dq.push_back({root, 0});
        while (!dq.empty()) {
            auto p = dq.front();
            dq.pop_front();
            if (p.second != current_layer) {
                p.first->next = nullptr;
                current_layer = p.second;
            } else {
                p.first->next = prev_node;
            }
            // Enqueue child: "right first"
            if (p.first->right) {
                dq.push_back({p.first->right, current_layer + 1});
            }
            if (p.first->left) {
                dq.push_back({p.first->left, current_layer + 1});
            }

            prev_node = p.first;
        }

        return root;

    }
};