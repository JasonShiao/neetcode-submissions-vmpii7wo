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
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto vvec = vector<vector<int>>{};
        if (root == nullptr) {
            return vvec;
        }

        queue<tuple<TreeNode*, int>> q{}; // (node, level) tuple
        q.push(make_tuple(root, 0));
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            TreeNode* n = get<0>(t);
            int level = get<1>(t);
            if (vvec.size() <= level) {
                vvec.push_back(vector<int>());
            }
            (vvec[level]).push_back(n->val);

            // add children to queue
            if (n->left != nullptr) {
                q.push(make_tuple(n->left, level+1));
            }
            if (n->right != nullptr) {
                q.push(make_tuple(n->right, level+1));
            }
        }

        return vvec;

    }
};
