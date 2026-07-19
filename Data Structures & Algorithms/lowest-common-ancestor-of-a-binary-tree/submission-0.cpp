/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return "nullptr" if neither p nor q in this subtree,
        // check three info:
        //    1. current node
        //    2. left branch
        //    3. right branch
        
        // 4 return cases:
        //   p, q, LCA, nullptr

        if (root == nullptr) {
            return root;
        }

        auto left_branch = lowestCommonAncestor(root->left, p, q);
        auto right_branch = lowestCommonAncestor(root->right, p, q);
        if (root == p || root == q) {
            // Regardless p or q exist in the subtree, 
            // root is the node to be returned
            return root;
        } else {
            // Case 1: not in subtree
            if (left_branch == nullptr && right_branch == nullptr) {
                return nullptr;
            }
            // Case 2: current node is LCA
            if ((left_branch == p && right_branch == q) || 
                (left_branch == q && right_branch == p)) {
                // this is the LCA
                return root;
            }
            // No need, this is redundant:
            // if LCA found in left_branch -> right_branch will only be nullptr
            // and vice versa
            // if (left_branch != nullptr && 
            //         left_branch != p && 
            //         left_branch != q) {
            //     return left_branch; // pass the LCA result to upper layer
            // } else if (right_branch != nullptr && 
            //             right_branch != p && 
            //             right_branch != q) {
            //     return right_branch; // pass the LCA result to upper layer
            // } 

            return (left_branch != nullptr ? left_branch : right_branch);
        }

    }
};