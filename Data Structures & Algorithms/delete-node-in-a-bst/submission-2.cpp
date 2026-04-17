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
    TreeNode* findMinNode(TreeNode* root) {
        TreeNode* cur = root;
        while (cur && cur->left) {
            cur = cur->left;
        }
        return cur;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return root;
        }

        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            // found the node, start delete process
            if (root->left == nullptr) {
                // return root->right as new root
                return root->right;
            } else if (root->right == nullptr) {
                return root->left;
            } else { // two leaves
                // 1. find min from the right branch
                TreeNode* min_node = findMinNode(root->right);
                // 2. assign the min val (on right) to the root
                root->val = min_node->val;
                // 3. delete the min node on the right
                // Notice: since it is the min of subtree, there is only no/one leaf
                // Notice: need to update root->right
                root->right = deleteNode(root->right, min_node->val);
            }
        }
        return root;
    }
};