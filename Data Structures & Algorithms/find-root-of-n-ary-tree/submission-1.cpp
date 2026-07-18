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
        // memory: O(n)
        // unordered_set<Node*> child_set;
        // for (auto n: tree) {
        //     for(auto c: n->children) {
        //         child_set.insert(c);
        //     }
        // }

        // for (auto n: tree) {
        //     if (child_set.find(n) == child_set.end()) {
        //         return n;
        //     }
        // }

        // Approach 2:
        // Key presumption for improvement: Each node has a unique value!!
        // Similar to dup value of array
        // every non-root node appear twice during the traversal:
        // once as a parent (can be leaf)
        // once as a child
        // and XOR the values will remove all dup values!
        // memory: O(1)
        int val = 0;
        for (auto n: tree) {
            val ^= n->val;
            for (auto c: n->children) {
                val ^= c->val;
            }
        }

        for (auto n: tree) {
            if (n->val == val) {
                return n;
            }
        }

    }
};
