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
    bool isValid(TreeNode* root, int lowerbound, int upperbound) {
        if (root == nullptr) {
            return true;
        }

        if (root->val >= upperbound || root->val <= lowerbound) {
            return false;
        }

        return isValid(root->left, lowerbound, root->val) &&
                isValid(root->right, root->val, upperbound);
    }

    bool isValidBST(TreeNode* root) {
        // Tips: start from the infinity bound (or largest possible), shrink gradually
        return isValid(root, -1001, 1001);
    }
};
