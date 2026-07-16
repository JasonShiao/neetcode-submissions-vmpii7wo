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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // Recursive
        TreeNode* merged_node = nullptr;
        if (root1 == nullptr && root2 == nullptr) {
            return merged_node;
        }

        if (root1 == nullptr) {
            merged_node = new TreeNode(root2->val);
            merged_node->left = mergeTrees(nullptr, root2->left);
            merged_node->right = mergeTrees(nullptr, root2->right);
        } else if (root2 == nullptr) {
            merged_node = new TreeNode(root1->val);
            merged_node->left = mergeTrees(root1->left, nullptr);
            merged_node->right = mergeTrees(root1->right, nullptr);
        } else {
            merged_node = new TreeNode(root1->val + root2->val);
            merged_node->left = mergeTrees(root1->left, root2->left);
            merged_node->right = mergeTrees(root1->right, root2->right);
        }

        return merged_node;
    }
};