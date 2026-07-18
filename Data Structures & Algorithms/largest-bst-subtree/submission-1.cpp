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
    int max_bst = 0;
public:
    // return <is bst, node cnt, min, max>
    tuple<bool, int, int, int> recursive(TreeNode* root) {
        if (root == nullptr) {
            return make_tuple(true, 0, -1, -1);
        }

        // check if current root is a bst
        auto t_left = recursive(root->left);
        auto t_right = recursive(root->right);
        bool is_bst = get<0>(t_left) && get<0>(t_right) &&
                    (root->left == nullptr || root->val > get<3>(t_left)) &&
                    (root->right == nullptr || root->val < get<2>(t_right));
        auto node_cnt = 1 + get<1>(t_left) + get<1>(t_right);
        auto cur_min = (root->left == nullptr ? 
                        root->val : get<2>(t_left));
        auto cur_max = (root->right == nullptr ? 
                        root->val : get<3>(t_right));

        // update the max bst
        if (is_bst) {
            max_bst = max(max_bst, node_cnt);
        }

        return make_tuple(is_bst, node_cnt, cur_min, cur_max);
    }

    int largestBSTSubtree(TreeNode* root) {
        // root is a BST iff
        // 1. both left and right are BST
        // 2. root < (min of right tree) && root > (max of left tree)
        // also return the node cnt
        recursive(root);

        return max_bst;
    }
};
