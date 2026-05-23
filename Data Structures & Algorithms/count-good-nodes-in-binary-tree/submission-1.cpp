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
    void dfs(TreeNode* n, int max_in_path, int& good_cnt) {
        // n is to be examined
        if (n == nullptr) {
            return;
        }

        if (n->val >= max_in_path) {
            good_cnt += 1;
            max_in_path = n->val;
        }

        dfs(n->left, max_in_path, good_cnt);
        dfs(n->right, max_in_path, good_cnt);
    }

    int goodNodes(TreeNode* root) {
        int good_cnt = 0;
        dfs(root, -101, good_cnt);

        return good_cnt;
    }
};
