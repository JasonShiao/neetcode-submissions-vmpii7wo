class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        // Cf. different from the problem that 
        //     allows to buy & sell at the same day
        int l = 0; // maintain l so that it always point to the lowest so far
        //int r = 1;
        int max_profit = 0;
        for (int r = 1; r < prices.size(); r++) {
            if (prices[r] < prices[l]) {
                // found a lower price, move l
                l = r;
            } else {
                // found a different r that is not lower than price at l
                // check
                int cand = prices[r] - prices[l];
                if (cand > max_profit) {
                    max_profit = cand;
                }
            }
        }
        return max_profit;
    }
};
