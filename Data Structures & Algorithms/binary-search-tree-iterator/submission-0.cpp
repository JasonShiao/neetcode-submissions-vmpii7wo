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
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        // Key: use a stack
        //      the next is the top of stack, no cursor needed!
        // strategy about puting node onto the stack for inorder:
        //   initially, push all the left nodes all the way down (the leftmost path of tree)
        //   when popping the top, check if it has right node,
        //        if it has, push the entire left path from such right node

        TreeNode* cur = root;
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
    }
    
    int next() {
        auto n = st.top();
        st.pop();
        // check right node exists and push the entire left path from right node
        TreeNode* cursor = n->right;
        while (cursor != nullptr) {
            st.push(cursor);
            // notice: push the left path
            cursor = cursor->left;
        }

        return n->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */