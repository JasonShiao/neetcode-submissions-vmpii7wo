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
    bool pathSum(TreeNode* root, const int& targetSum, int cur_sum) {
        if (root == nullptr) {
            return false; // not a leaf
        }

        // check whether a leaf
        if (root->left == nullptr && root->right == nullptr) {
            if ((root->val + cur_sum) == targetSum) {
                return true;
            } else {
                return false;
            }
        }

        cur_sum += root->val;
        if (pathSum(root->left, targetSum, cur_sum)) {
            return true;
        } else if (pathSum(root->right, targetSum, cur_sum)) {
            return true;
        } else {
            cur_sum -= root->val;
        }
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int cur_sum = 0;
        return pathSum(root, targetSum, cur_sum);
    }
};