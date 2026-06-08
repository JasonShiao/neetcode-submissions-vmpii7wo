class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9 cols, 9 rows, 9 blocks
        // 27 sets in total
        // every time adding a new num
        // check 3 sets and find if already exist
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> rows(9);
        vector<vector<unordered_set<char>>> blocks(3,vector<unordered_set<char>>(3));
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (board[r][c] == '.') {
                    continue;
                }
                // col
                if (cols[c].find(board[r][c]) != cols[c].end()) {
                    return false;
                }
                if (rows[r].find(board[r][c]) != rows[r].end()) {
                    return false;
                }
                if (blocks[r/3][c/3].find(board[r][c]) != blocks[r/3][c/3].end()) {
                    return false;
                }
                // add to sets
                cols[c].insert(board[r][c]);
                rows[r].insert(board[r][c]);
                blocks[r/3][c/3].insert(board[r][c]);
            }
        }

        return true;
    }
};
