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
    double max_avg;
public:
    // Return the <sum, node cnt> of the subtree
    pair<long long, int> recursive(TreeNode* root) {
        pair<long long, int> res;

        if (root == nullptr) {
            return {0, 0};
        }
        auto res_l = recursive(root->left);
        auto res_r = recursive(root->right);

        res.first = res_l.first + res_r.first + root->val;
        res.second = res_l.second + res_r.second + 1;

        // Update max avg
        // NOTICE: Remember to convert to double before division!!!
        double avg = (double)res.first / (res.second);
        max_avg = avg > max_avg ? avg : max_avg;

        return res;
    }

    double maximumAverageSubtree(TreeNode* root) {
        max_avg = 0;
        recursive(root);
        return max_avg;
    }
};
