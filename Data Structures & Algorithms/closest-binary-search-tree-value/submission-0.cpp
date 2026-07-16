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
    int closestValue(TreeNode* root, double target) {
        // if target > node, check current node and right branch only
        // if target < node, check current node and left branch only

        if (root->left == nullptr && root->right == nullptr) {
            // already the leaf -> itself is the closest in subtree
            return root->val;
        }

        if (root->val == target) {
            return root->val; // already the closest
        } else if (root->val > target) {
            // search left branch
            if (root->left == nullptr) {
                return root->val;
            }
            int cand = closestValue(root->left, target);
            if (abs(cand - target) <= abs(root->val - target)) {
                return cand;
            } else {
                return root->val;
            }
        } else {
            // search right branch
            if (root->right == nullptr) {
                return root->val;
            }
            int cand = closestValue(root->right, target);
            if (abs(cand - target) < abs(root->val - target)) {
                return cand;
            } else {
                return root->val;
            }
        }

    }
};
