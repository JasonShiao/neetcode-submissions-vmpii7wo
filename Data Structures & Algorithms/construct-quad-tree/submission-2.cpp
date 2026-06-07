/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* recursion(int r, int c, int grid_size, vector<vector<int>>& grid) {
        // explore 4 neighbor
        Node* root = new Node();
        if (grid_size == 1) {
            if (grid[r-1][c-1] == grid[r-1][c] && 
                grid[r-1][c] == grid[r][c-1] &&
                grid[r][c-1] == grid[r][c]) {
                root->val = grid[r-1][c-1];
                root->isLeaf = true;
                return root;
            } else {
                root->topLeft = new Node(grid[r-1][c-1], true);
                root->topRight = new Node(grid[r-1][c], true);
                root->bottomLeft = new Node(grid[r][c-1], true);
                root->bottomRight = new Node(grid[r][c], true);
                root->isLeaf = false;
                return root;
            }
        }

        int sub_grid_size = grid_size / 2;
        Node* top_left = recursion(r - sub_grid_size, c - sub_grid_size, sub_grid_size, grid);
        Node* top_right = recursion(r - sub_grid_size, c + sub_grid_size, sub_grid_size, grid);
        Node* bottom_left = recursion(r + sub_grid_size, c - sub_grid_size, sub_grid_size, grid);
        Node* bottom_right = recursion(r + sub_grid_size, c + sub_grid_size, sub_grid_size, grid);
        if (top_left->isLeaf && top_right->isLeaf && bottom_left->isLeaf && bottom_right->isLeaf
            && top_left->val == top_right->val && top_right->val == bottom_left->val && 
            bottom_left->val == bottom_right->val) {
            // destruct sub leaves -> set leaf to current node
            root->isLeaf = true;
            root->val = top_left->val;
        } else {
            root->topLeft = top_left;
            root->topRight = top_right;
            root->bottomLeft = bottom_left;
            root->bottomRight = bottom_right;
        }

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        if (grid.size() == 1) {
            Node* root = new Node(grid[0][0], true);
            return root;
        }

        return recursion(grid.size() / 2, grid.size() / 2, grid.size() / 2, grid);
    }
};