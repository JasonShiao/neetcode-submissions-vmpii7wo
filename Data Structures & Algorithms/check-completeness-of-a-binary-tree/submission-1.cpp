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
    bool isCompleteTree(TreeNode* root) {
        // BFS: check each level
        if (root == nullptr) {
            return true;
        }

        deque<TreeNode*> dq;
        dq.push_back(root);
        int level = 0;
        while (!dq.empty()) {
            int level_size = dq.size();
            bool level_terminated = false; // mark next level terminate pos
            for (int i = 0; i < level_size; i++) {
                auto n = dq.front();
                dq.pop_front();

                // Idea: if terminated (null) happens before, 
                //       it MUST not be any non null node
                if (n->left) {
                    if (level_terminated) {
                        return false;
                    }
                    dq.push_back(n->left);
                } else {
                    level_terminated = true;
                }
                if (n->right) {
                    if (level_terminated) {
                        return false;
                    }
                    dq.push_back(n->right);
                } else {
                    level_terminated = true;
                }

            }

            // Ensure complete level (except for the last level)
            if (dq.size() > 0) { // has next level -> assert current level's size
                if (level_size != (1 << level)) {
                    return false;
                }
            }
            level += 1;
        }

        return true;
    }
};