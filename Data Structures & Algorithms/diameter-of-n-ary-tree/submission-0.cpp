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
private:
    int longest_path = 0;
public:
    int recursive(Node* root) {
        // return the longest subtree + 1
        if (root == nullptr) {
            return -1;
        }

        int longest_branch = -1;
        int second_longest_branch = -1;
        for (auto c: root->children) {
            int branch_len = recursive(c);
            if (branch_len >= longest_branch) {
                second_longest_branch = longest_branch;
                longest_branch = branch_len;
            } else if (branch_len >= second_longest_branch) {
                second_longest_branch = branch_len;
            }
        }

        // update the longest diameter inside the process
        // sum both side's length + 1
        longest_path = max(longest_path, 
                        longest_branch + second_longest_branch + 2);

        return longest_branch + 1;
    }

    int diameter(Node* root) {
        recursive(root);
        return longest_path;
    }
};
