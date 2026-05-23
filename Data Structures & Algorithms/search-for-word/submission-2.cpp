class Solution {
public:
    bool backtrack(vector<vector<char>>& board,
        int row, int col, 
        vector<vector<bool>>& visited, const string& word,
        int cur_len) {
        // if already found from the previous cell
        if (cur_len == word.length()) {
            return true;
        }

        // validate current cell
        if (row >= board.size() || row < 0 || 
            col >= board[0].size() || col < 0) {
            return false;
        }
        if (visited[row][col]) {
            return false;
        }

        bool res = false;
        if (board[row][col] == word[cur_len]) { // one char further
            cur_len += 1; // after adding the current cell
            visited[row][col] = true;

            res =  backtrack(board, row + 1, col, visited, 
            word, cur_len) ||
                backtrack(board, row - 1, col, visited, 
            word, cur_len) ||
                backtrack(board, row, col + 1, visited, 
            word, cur_len) ||
                backtrack(board, row, col - 1, visited, 
            word, cur_len);

            visited[row][col] = false;
        }

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // need a map to check whether the cell is visited
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        bool res = false;
        // try all possible start cell
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (backtrack(board, i, j, visited, word, 0)) {
                    res = true;
                    break;
                }
            }
        }

        return res;
    }
};
