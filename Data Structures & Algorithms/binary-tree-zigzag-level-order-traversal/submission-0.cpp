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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // For each level, push onto a (FILO) stack first.
        // at the end of the level, pop the stack to enqueue
        // at odd level, push right first
        // at even level, push left first
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        int level = 0;
        while (!dq.empty()) {
            int level_size = dq.size();
            stack<TreeNode*> level_st;
            vector<int> level_v;
            for (int i = 0; i < level_size; i++) {
                auto n = dq.front();
                dq.pop_front();

                // process: push to res
                level_v.push_back(n->val);

                // should be careful left first or right first for each level
                if (level % 2) {
                    if (n->right) level_st.push(n->right);
                    if (n->left) level_st.push(n->left);
                } else {
                    if (n->left) level_st.push(n->left);
                    if (n->right) level_st.push(n->right);
                }
            }
            // move level v to res
            res.emplace_back(level_v);

            // pop stack and enqueue -> to reverse the order for next level
            while (!level_st.empty()) {
                dq.push_back(level_st.top());
                level_st.pop();
            }

            // Remember to update level
            level += 1;
        }

        return res;
    }
};