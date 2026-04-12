class Solution {
public:
    int climbStairs(int n) {
        // one-step jump in the end: cnt[i-1]+1
        // two-step jump in the end: cnt[i-2]+1
        int dp[2] = {1, 2};
        if (n <= 2) {
            return dp[n-1];
        }
        int result = 0;
        for (int i = 2; i < n; i++) {
            int temp = dp[1];
            dp[1] = dp[0] + dp[1];
            result = dp[1];
            dp[0] = temp;
        }

        return result;
    }
};
