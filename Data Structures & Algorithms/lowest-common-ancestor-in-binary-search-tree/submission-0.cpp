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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if ((p->val - root->val) * (q->val - root->val) < 0) {
            // on opposite side, the root is the lowest LCA
            return root;
        } else if ((p->val - root->val) * (q->val - root->val) == 0) {
            // either p / q is root
            return (p->val - root->val) == 0 ? p : q;
        }

        // on same side
        if (p->val - root->val > 0) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return lowestCommonAncestor(root->left, p, q);
        }

    }
};
