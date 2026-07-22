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
    TreeNode* recursive(vector<int>& inorder, vector<int>& postorder,
                int l_inorder, int r_inorder, 
                int l_postorder, int r_postorder) {
        if (l_inorder > r_inorder) {
            return nullptr;
        }
        if (l_inorder == r_inorder) {
            TreeNode* leaf = new TreeNode(inorder[l_inorder]);
            return leaf;
        }

        // 1. root is the last element of postorder
        int root_val = postorder[r_postorder];
        TreeNode* root = new TreeNode(root_val);
        // 2. search for root in inorder
        for (int i = l_inorder; i <= r_inorder; i++) {
            if (inorder[i] == root_val) {
                root->left = recursive(inorder, postorder,
                                    l_inorder, i - 1, 
                                    l_postorder, l_postorder + (i - l_inorder) - 1);
                root->right = recursive(inorder, postorder,
                                    i + 1, r_inorder, 
                                    l_postorder + (i - l_inorder), r_postorder - 1);
                break;
            }
        }

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Insight:
        // 1. use post order array to get root val
        // 2. with the root val, divide the inorder array into two trees
        // 3. based on the division of inorder, divide the post order and
        //    repeat the same process

        return recursive(inorder, postorder, 
                0, inorder.size() - 1,
                0, postorder.size() - 1);
    }
};