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
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        // terminate condition
        if (subRoot == nullptr && root == nullptr) {
            return true;
        } else if (subRoot == nullptr || root == nullptr) {
            return false;
        }

        // both are non nullptr when reaching here

        return isSame(root->left, subRoot->left) &&
                isSame(root->right, subRoot->right) &&
                root->val == subRoot->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // terminate condition
        if (root == nullptr && subRoot == nullptr) {
            return true;
        } else if (root == nullptr) {
            return false;
        }

        // has already ensure not nullptr

        bool res = isSubtree(root->left, subRoot) ||
                isSubtree(root->right, subRoot);

        // Check if subtree start from the current root
        res |= isSame(root, subRoot);

        return res;
    }
};
