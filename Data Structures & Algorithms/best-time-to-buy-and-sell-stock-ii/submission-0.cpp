class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // my idea: peak detection
        // if price ascending -> keep moving sell cursor
        // once price drop -> start moving buy cursor until a lowest price befor the sell cursor
        // sell cursor
        // buy cursor
        int profit = 0;
        prices.push_back(0); // append 0 for cleaner handling
        int buy_cursor = 0;
        int sell_cursor = 0;
        while (sell_cursor < (prices.size() - 1)) {
            if (prices[sell_cursor + 1] < prices[sell_cursor]) {
                // the buy is the first index (since we guarantee the window is monotonically ascending)
                // update profit
                profit += (prices[sell_cursor] - prices[buy_cursor]);
                // update cursor
                buy_cursor = sell_cursor + 1;
            }
            sell_cursor += 1;
        }
        return profit;

    }
};