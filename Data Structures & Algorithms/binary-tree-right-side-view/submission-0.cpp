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
    vector<int> rightSideView(TreeNode* root) {
        auto vec = vector<int>{};
        if (root == nullptr) {
            return vec;
        }

        int level = -1;
        queue<tuple<TreeNode*, int>> q{};
        q.push(make_tuple(root, 0));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            TreeNode* n = get<0>(t);
            int n_level = get<1>(t);

            if (n_level > level) {
                vec.push_back(n->val);
                level = n_level;
            }
            // right first
            if (n->right != nullptr) {
                q.push(make_tuple(n->right, n_level+1));
            }
            if (n->left != nullptr) {
                q.push(make_tuple(n->left, n_level+1));
            }

        }

        return vec;
    }
};
