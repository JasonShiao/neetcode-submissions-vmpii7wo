class TicTacToe {
private:
    int n_;
    vector<vector<int>> board_;
public:
    TicTacToe(int n) {
        n_ = n;
        board_ = vector<vector<int>>(n, vector<int>(n, -1)); // -1 for empty
    }
    
    int move(int row, int col, int player) {
        // Tips: only need to check cells related to the current move
        board_[row][col] = player;

        // check all rows with col
        bool win_detected = true;
        for (int r = 0; r < n_; r++) {
            if (board_[r][col] != player) {
                win_detected = false;
                break;
            }
        }
        if (win_detected) {
            return player;
        }

        win_detected = true;
        // check all cols with row
        for (int c = 0; c < n_; c++) {
            if (board_[row][c] != player) {
                win_detected = false;
                break;
            }
        }
        if (win_detected) {
            return player;
        }

        // check diagonal ()
        if (row == col) {
            win_detected = true;
            for (int i = 0; i < n_; i++) {
                if (board_[i][i] != player) {
                    win_detected = false;
                    break;
                }
            }
            if (win_detected) {
                return player;
            }
        }
        if ((n_ - row - 1) == col) {
            win_detected = true;
            for (int i = 0; i < n_; i++) {
                if (board_[n_-1-i][i] != player) {
                    win_detected = false;
                    break;
                }
            }
            if (win_detected) {
                return player;
            }
        }
    

        // no winner
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
