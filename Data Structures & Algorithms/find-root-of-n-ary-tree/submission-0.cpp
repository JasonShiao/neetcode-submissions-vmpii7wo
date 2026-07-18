/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        // Intuition: Root is not a child of any node

        // Approach 1: use a set to store child nodes
        unordered_set<Node*> child_set;
        for (auto n: tree) {
            for(auto c: n->children) {
                child_set.insert(c);
            }
        }

        for (auto n: tree) {
            if (child_set.find(n) == child_set.end()) {
                return n;
            }
        }
    }
};
