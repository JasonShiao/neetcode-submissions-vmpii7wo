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
    pair<int, int> dfs(TreeNode* root) {
        // return max for not select root & select root
        if (!root) {
            return {0, 0};
        }

        auto l_tree = dfs(root->left);
        auto r_tree = dfs(root->right);

        // if not select root -> the left/right can be select or not select -> choose the max of them
        // if select root -> left/right can only be unselect
        return {max(l_tree.first, l_tree.second) + max(r_tree.first, r_tree.second), 
                root->val + l_tree.first + r_tree.first}; // {not select root, select root}
    }

    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};