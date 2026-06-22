class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> min_to_target;

        // sort if not sorted yet
        sort(coins.begin(), coins.end());

        min_to_target[0] = 0;
        for (int i = 1; i <= amount; i++) {
            min_to_target[i] = INT_MAX;
        }
        
        for (int i = 1; i <= amount; i++) {
            int min_coin = INT_MAX;
            for (auto coin: coins) {
                if (i - coin >= 0 && min_to_target[i - coin] != INT_MAX) {
                    min_coin = min(min_coin, min_to_target[i - coin] + 1);
                }
            }
            min_to_target[i] = min_coin;
        }
        
        return min_to_target[amount] == INT_MAX ? -1 : min_to_target[amount];
    }
};
