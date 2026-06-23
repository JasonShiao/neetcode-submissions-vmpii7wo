class Solution {
public:
    int dfs(int n, int num, vector<int>& dp) {
        if (num == 1) {
            return 1;
        }
        
        // Use dp to skip duplicate
        if (dp[num] != -1) {
            return dp[num];
        }

        // divide into two positive numbers
        // NOTICE: this condition for initialize res is critical!!!
        // As long as we're not at the original target,
        //   we can have result without split
        int res = (n == num ? 0 : num);
        // =====================================================
        for (int i = 1; i < num; i++) { // n-2 possible partitions
            // keep update the max
            res = max(res, dfs(n, i, dp) * dfs(n, num - i, dp));
        }

        dp[num] = res;
        return res;
    }

    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        // each layer -> divide into two positive numbers (n-2 possible partitions)
        return dfs(n, n, dp);
    }
};