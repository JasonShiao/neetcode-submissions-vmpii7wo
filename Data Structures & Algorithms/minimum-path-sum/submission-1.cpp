class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        // NOTE: single row of memo is enough!!
        vector<int> dp(COLS, INT_MAX);
        dp[0] = 0;
        
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (c == 0) {
                    dp[c] = dp[c] + grid[r][c];
                } else {
                    dp[c] = min(dp[c-1], dp[c]) + grid[r][c];
                }
            }
        }

        return dp[COLS-1];
    }
};