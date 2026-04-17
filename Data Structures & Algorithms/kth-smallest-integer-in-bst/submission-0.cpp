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
    vector<int> inorder(TreeNode* root, int k) {
        if (root == nullptr) {
            return vector<int>();
        }

        vector<int> vec{};
        auto vec_left = inorder(root->left, k);
        vec.insert(vec.end(), vec_left.begin(), vec_left.end());
        // skip when reach k elements
        if (vec.size() > k) {
            return vec;
        }
        vec.push_back(root->val);
        // skip when reach k elements
        if (vec.size() > k) {
            return vec;
        }
        auto vec_right = inorder(root->right, k);
        vec.insert(vec.end(), vec_right.begin(), vec_right.end());
        
        return vec;
    }

    int kthSmallest(TreeNode* root, int k) {
        auto vec = inorder(root, k);
        return vec[k-1];
    }
};
