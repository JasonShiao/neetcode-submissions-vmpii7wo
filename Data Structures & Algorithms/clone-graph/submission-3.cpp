/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node*, Node*> oldToNew;
        // NOTICE: Nodes in the queue have already had a cloned corresponding node and value
        queue<Node*> q;

        oldToNew[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for (Node* nei : cur->neighbors) {
                // lazy create (create only when needed)
                if (oldToNew.find(nei) == oldToNew.end()) {
                    oldToNew[nei] = new Node(nei->val);
                    q.push(nei);
                }

                oldToNew[cur]->neighbors.push_back(oldToNew[nei]);
            }
        }

        return oldToNew[node];
    }
};
