class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); // row
        int n = obstacleGrid[0].size(); // col
        vector<int> dp(n, 0);
        dp[n-1] = 1;
        // row by row
        for (int i = m - 1; i >= 0; i--) {
            // no right dir for the rightmost col
            // remain the same (as the down row) or reset to 0 (obstacle)
            if (obstacleGrid[i][n-1] == 1) {
                dp[n-1] = 0;
            }
            // normal for the rest cols
            for (int j = n-2; j >= 0; j--) {
                // include info of obstacle: set 0 where obstacle exist
                if (obstacleGrid[i][j] == 1) { // on the obstacle
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j+1];
                }
            }
        }

        return dp[0];

    }
};