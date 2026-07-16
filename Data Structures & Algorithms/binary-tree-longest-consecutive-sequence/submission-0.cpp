/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        // path always from parent to child
        // consec sequence in increasing order

        // recursive
        if (root == nullptr) {
            return 0;
        }

        int max_len = 1;
        // if child exists
        if (root->left) {
            int cand_len = longestConsecutive(root->left);
            if (root->left->val == (root->val + 1)) {
                cand_len += 1;
            }
            max_len = max(max_len, cand_len);
        }
        if (root->right) {
            int cand_len = longestConsecutive(root->right);
            if (root->right->val == (root->val + 1)) {
                cand_len += 1;
            }
            max_len = max(max_len, cand_len);
        }
        return max_len;
    }
};
