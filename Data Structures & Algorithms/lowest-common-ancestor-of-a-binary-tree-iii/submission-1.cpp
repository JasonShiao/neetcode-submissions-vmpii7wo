/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        // 1. Naive approach: storing all visited nodes
        //    if a new visit node is in the visited nodes, it is the LCA
        //    memory: O(n)
        // 
        // Alternative: trace back to root from p first and store all visited in the path
        //    then trace back from q and return the first visited node in p's path
        unordered_set<Node*> visited;
        Node* cur1 = p;
        Node* cur2 = q;
        while (cur1 != nullptr || cur2 != nullptr) {
            // Notice: Order doesn't matter
            if (cur1 != nullptr) {
                if (visited.find(cur1) != visited.end()) {
                    return cur1;
                } else {
                    visited.insert(cur1);
                    cur1 = cur1->parent;
                }
            }
            if (cur2 != nullptr) {
                if (visited.find(cur2) != visited.end()) {
                    return cur2;
                } else {
                    visited.insert(cur2);
                    cur2 = cur2->parent;
                }
            }
        }

        return nullptr;

        // 2. 

    }
};