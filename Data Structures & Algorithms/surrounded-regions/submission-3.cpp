class Solution {
public:
    // similar to Pacific Atlantic water flow problem

    // Key issue: when DFS, there will be cycles!!
    // how to handle them? or workaround?
    // start from border -> DFS -> mark as visited and preserve 'O'
    // all the unvisited 'O' should be flipped into 'X'

    void dfs(vector<vector<char>>& board, 
            set<pair<int, int>>& visited, int r, int c) {
        // return true if can reach border -> don't flip to 'X'
        // return false otherwise -> flip to 'X'
        if (min(r, c) < 0 || r >= board.size() || c >= board[0].size()) {
            return;
        }

        if (visited.find({r, c}) != visited.end()) {
            return;
        }

        if (board[r][c] == 'X') {
            return;
        }

        // Add to preserve set
        visited.insert({r, c});

        // search neighboring 'O'
        vector<vector<int>> neighbors = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}
        };
        for (auto n: neighbors) {
            dfs(board, visited, r + n[0], c + n[1]);
        }

    }

    void solve(vector<vector<char>>& board) {
        // insight: if a region is not surrounded, 
        // it must connect to the edge (border)

        // start from all cells in the border
        int rows = board.size();
        int cols = board[0].size();
        set<pair<int, int>> visited;
        // top and bottom
        for (int c = 0; c < cols; c++) {
            if (board[0][c] == 'O' && visited.find({0, c}) == visited.end()) {
                dfs(board, visited, 0, c);
            }
            if (board[rows - 1][c] == 'O' && visited.find({rows - 1, c}) == visited.end()) {
                dfs(board, visited, rows - 1, c);
            }
        }
        // left and right
        for (int r = 1; r < rows - 1; r++) {
            if (board[r][0] == 'O' && visited.find({r, 0}) == visited.end()) {
                dfs(board, visited, r, 0);
            }
            if (board[r][cols-1] == 'O' && visited.find({r, cols-1}) == visited.end()) {
                dfs(board, visited, r, cols - 1);
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                // 'O' and not preserved -> flip to 'X'
                if (board[r][c] == 'O' && visited.find({r, c}) == visited.end()) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
