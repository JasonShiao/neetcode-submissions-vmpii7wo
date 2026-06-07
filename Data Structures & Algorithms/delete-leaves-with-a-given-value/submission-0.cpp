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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) {
            return nullptr;
        }

        // process left and right
        TreeNode* left = removeLeafNodes(root->left, target);
        root->left = left;
        TreeNode* right = removeLeafNodes(root->right, target);
        root->right = right;

        // post order process
        if (!root->left && !root->right) { // a leaf
            if (root->val == target) { // remove
                delete root;
                return nullptr;
            } else {
                return root;
            }
        } else {
            return root;
        }
    }
};