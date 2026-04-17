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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>();
        }

        vector<int> vec{};
        auto left_vec = inorderTraversal(root->left);
        vec.insert(vec.end(), left_vec.begin(), left_vec.end());
        vec.push_back(root->val);
        auto right_vec = inorderTraversal(root->right);
        vec.insert(vec.end(), right_vec.begin(), right_vec.end());

        return vec;
    }
};