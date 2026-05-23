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
    int max_diameter = 0;
public:
    int heightOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return -1; // to make the leaf node height = 0
        }

        int left_height = heightOfBinaryTree(root->left);
        int right_height = heightOfBinaryTree(root->right);
        int height =  1 + max(left_height, right_height);

        if ((left_height + 2 + right_height) > max_diameter) {
            max_diameter = (left_height + 2 + right_height);
        }

        return height;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // if passing parent (root), will always use the "height" of the branch (subtree)


        // For each node Add height from left and height from right
        heightOfBinaryTree(root);

        return max_diameter;
    }
};
