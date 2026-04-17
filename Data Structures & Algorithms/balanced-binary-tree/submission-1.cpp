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
    int get_height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        return 1 + max(get_height(root->left), get_height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        if (!isBalanced(root->left) || !isBalanced(root->right)) {
            return false;
        }

        if (abs(get_height(root->left) - get_height(root->right)) <= 1) {
            return true;
        } else {
            return false;
        }
        
    }
};
