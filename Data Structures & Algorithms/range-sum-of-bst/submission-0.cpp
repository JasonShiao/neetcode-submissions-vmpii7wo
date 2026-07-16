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
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Strategy:
        //   if parent < low, check right child only
        //   if parent > high, check left child only
        //   if low < parent < high, check both child

        // Terminate condition, handle nullptr
        if (root == nullptr) {
            return 0;
        }

        // Recursion:
        //   Collect the result from the subtree,
        //   add the current node
        //  and return the result to parent
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        } else if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        } else {
            int res = rangeSumBST(root->right, low, high) +
                    rangeSumBST(root->left, low, high) +
                    root->val;
            return res;
        }

    }
};