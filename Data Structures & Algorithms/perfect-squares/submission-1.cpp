class Solution {
public:
    int numSquares(int n) {
        //unordered_map<int, int> dp; // i -> least number of squares for i
        vector<int> dp(n+1, 0);

        vector<int> sq_list;
        // WARNING: start from 1 instead of 0 !!!!
        for (int i = 1; i <= n; i++) {
            if (i * i <= n) {
                sq_list.push_back(i*i);
            } else {
                break;
            }
        }

        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int least_num_sq = INT_MAX;
            for (auto sq: sq_list) {
                if (i - sq >= 0) {
                    least_num_sq = min(least_num_sq, dp[i - sq] + 1);
                }
            }
            dp[i] = least_num_sq;
        }

        return dp[n];
    }
};