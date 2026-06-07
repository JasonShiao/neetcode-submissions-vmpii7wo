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
    // TreeNode* recursionBuild(vector<int>& preorder, vector<int>& inorder, 
    //     int start, int end) {
    //     // [start, end] inclusive

    //     if (start > end) {
    //         return nullptr;
    //     }

    //     TreeNode* root = new TreeNode(preorder[start]);
    //     int mid = start;
    //     // find the index of root in inorder
    //     while (true) {
    //         if (inorder[mid] == root->val) {
    //             break;
    //         }
    //         mid += 1;
    //     }
    //     root->left = recursionBuild(preorder, inorder, start, mid - 1);
    //     root->right = recursionBuild(preorder, inorder, mid + 1, end);

    //     return root;
    // }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // recursion
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};
