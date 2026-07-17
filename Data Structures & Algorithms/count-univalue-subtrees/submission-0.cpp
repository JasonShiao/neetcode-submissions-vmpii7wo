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
    bool recursive(TreeNode* root, int& unival_cnt) {
        // return whether it is a uni-value subtree 
        // and also update the res counter

        // handle special case
        if (root == nullptr) {
            return false;
        }

        bool res = true;
        if (root->left) {
            res &= recursive(root->left, unival_cnt) && 
                    (root->val == root->left->val);
        }
        if (root->right) {
            res &= recursive(root->right, unival_cnt) &&
                    (root->val == root->right->val);
        }

        if (res) {
            // update count
            unival_cnt += 1;
        }

        return res;
    }

    int countUnivalSubtrees(TreeNode* root) {
        // A tree can only be uni-value subtree if 
        // 1. both subtrees are uni-value and 
        // 2. value is the same as root node's value

        int cnt = 0;
        recursive(root, cnt);

        return cnt;
    }
};
