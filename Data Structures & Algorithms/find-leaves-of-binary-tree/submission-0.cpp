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
private:
    unordered_map<int, vector<int>> level_groups;

    int dfs_level(TreeNode* root) {
        int res = 0;
        if (root == nullptr) {
            return res;
        }

        if (root->left == nullptr && root->right == nullptr) {
            // leaf node -> level 1
            res = 1;
        } else {
            res = max(dfs_level(root->left), 
                    dfs_level(root->right)) + 1;
        }
        level_groups[res].push_back(root->val);

        return res;
    }

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        // Collect info from child
        // level of the parent is the max(r_child level, l_child level) + 1

        int max_level = dfs_level(root);
        vector<vector<int>> res;
        for (int i = 1; i <= max_level; i++) {
            res.emplace_back(level_groups[i]);
        }

        return res;
    }
};
