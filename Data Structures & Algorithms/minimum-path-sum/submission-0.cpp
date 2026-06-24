class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        vector<vector<int>> dp(ROWS, 
                        vector<int>(COLS, 0));
        
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (r == 0 && c == 0) {
                    dp[r][c] = grid[0][0];
                } else if (r == 0) {
                    // can only go from left to right
                    dp[r][c] = dp[r][c-1] + grid[r][c];
                } else if (c == 0) {
                    // can only go from up to down
                    dp[r][c] = dp[r-1][c] + grid[r][c];
                } else {
                    dp[r][c] = min(dp[r][c-1], dp[r-1][c]) + grid[r][c];
                }
            }
        }

        return dp[ROWS-1][COLS-1];
    }
};