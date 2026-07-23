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
    int recursive(TreeNode* root, int prev_path) {
        // sum of path to leaf nodes in the subtree
        if (root == nullptr) {
            return 0;
        }
        if (!root->left && !root->right) {
            // root is the leaf
            return (prev_path * 10 + root->val);
        }
        int res = 0;
        res += recursive(root->left, prev_path * 10 + root->val);
        res += recursive(root->right, prev_path * 10 + root->val);

        return res;
    }
    int sumNumbers(TreeNode* root) {
        return recursive(root, 0);
    }
};