class Solution {
public:
    // return the number of comb for target
    int orderedCombinations(vector<int>& nums, 
        unordered_map<int, int>& dp, int target) {

        if (target < 0) {
            return 0;
        } else if (target == 0) {
            // One branch end with success
            return 1;
        }
        
        // Complexity: O(TxN)
        // At most T layers, each layer have N branches
        // **because each layer will decrement target by at least 1**

        // branching for each num with memoization
        int res = 0;
        for (auto num: nums) {
            // if dp[..] exists, use it directly to skip duplicate explore
            // otherwise, construct it and then use it
            if (dp.find(target - num) == dp.end()) {
                int new_comb = orderedCombinations(nums, dp, target - num);
                dp[target - num] = new_comb;
            }
            res += dp[target - num];
        }

        return res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> dp; // <target, num of ordered comb>
        return orderedCombinations(nums, dp, target);
    }
};