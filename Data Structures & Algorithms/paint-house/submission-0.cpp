class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // thinking:
        // maintain info about if idx is a specific color, 
        // what is the min cost
        
        // Exploit such info for the next idx!!1
        int min_cost_dp[3] = {0, 0, 0};
        for (int i = 0; i < costs.size(); i++) {
            int min_for_c[3] = {INT_MAX, INT_MAX, INT_MAX};
            for (int c = 0; c < 3; c++) {
                for (int prev_c = 0; prev_c < 3; prev_c++) {
                    if (c == prev_c) continue;
                    // choose the optimal pair
                    min_for_c[c] = min(min_for_c[c], min_cost_dp[prev_c] + costs[i][c]);
                }
            }
            min_cost_dp[0] = min_for_c[0];
            min_cost_dp[1] = min_for_c[1];
            min_cost_dp[2] = min_for_c[2];
        }

        // select the min of the final state
        return min(min_cost_dp[0], min(min_cost_dp[1], min_cost_dp[2]));
    }
};

// [18, 33, 7] -> [21, 10, 37]