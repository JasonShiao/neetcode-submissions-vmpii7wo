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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // key: pos
        unordered_map<int, vector<int>> res_map;
        int min_pos = 0;
        int max_pos = 0;

        if (root == nullptr) {
            return {};
        }

        // BFS instead of DFS!!!
        // since top layer should be appended first!!
        deque<pair<TreeNode*, int>> dq;
        dq.push_back({root, 0}); // <node, pos>
        while (!dq.empty()) {
            auto p = dq.front();
            dq.pop_front();

            // add to map
            res_map[p.second].push_back(p.first->val);
            min_pos = min(p.second, min_pos);
            max_pos = max(p.second, max_pos);

            // enqueue the child
            if (p.first->left) {
                dq.push_back({p.first->left, p.second - 1});
            }
            if (p.first->right) {
                dq.push_back({p.first->right, p.second + 1});
            }
        }

        // convert from map to vec
        vector<vector<int>> res;
        for (int i = min_pos; i <= max_pos; i++) {
            res.push_back(res_map[i]);
        }

        return res;
    }
};