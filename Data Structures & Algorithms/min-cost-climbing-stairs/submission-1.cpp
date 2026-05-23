class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 1) {
            return cost[0];
        } else if (cost.size() == 2) {
            return min(cost[0], cost[1]);
        }

        // store cost to i for the previous 2 index
        int i = 2;
        int prev_cost[2] = {0, 0}; // 0 for front, 1 for latter
        while (i <= cost.size()) {
            int new_cost = min(prev_cost[0] + cost[i-2], 
                                prev_cost[1] + cost[i-1]);
            prev_cost[0] = prev_cost[1];
            prev_cost[1] = new_cost;

            i += 1;
        }

        return prev_cost[1];
    }
};
