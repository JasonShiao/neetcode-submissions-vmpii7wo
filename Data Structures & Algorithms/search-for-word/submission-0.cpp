class Solution {
public:
    bool backtrack(vector<vector<char>>& board,
        int row, int col, 
        vector<vector<bool>>& visited, const string& word,
        string s) {
        if (row >= board.size() || row < 0 || 
            col >= board[0].size() || col < 0) {
            return false;
        }
        if (visited[row][col]) {
            return false;
        }

        s += board[row][col];

        // NOTICE the condition
        if (s.length() > word.length()) {
            return false;
        }
        if (word.substr(0, s.length()) != s) {
            return false;
        }
        if (s == word) {
            return true;
        }
        // ===================

        // current cell is processed
        visited[row][col] = true;

        bool res =  backtrack(board, row + 1, col, visited, 
            word, s) ||
                backtrack(board, row - 1, col, visited, 
            word, s) ||
                backtrack(board, row, col + 1, visited, 
            word, s) ||
                backtrack(board, row, col - 1, visited, 
            word, s);
        
        visited[row][col] = false;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // need a map to check whether the cell is visited
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        bool res = false;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, i, j, visited, word, "")) {
                    res = true;
                    break;
                }
            }
        }

        return res;
    }
};
