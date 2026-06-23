class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // target = total/2
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) {
            return false;
        }

        int target = total / 2;

        // unordered_set<int> possible_sum;
        // possible_sum.insert(0); // this is critical
        // for (auto num: nums) {
        //     unordered_set<int> new_possible_sum;
        //     for (auto t: possible_sum) {
        //         new_possible_sum.insert(t + num);
        //         new_possible_sum.insert(t);
        //     }
        //     possible_sum = new_possible_sum;
        // }

        // if (possible_sum.find(target) == possible_sum.end()) {
        //     return false;
        // } else {
        //     return true;
        // }

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int sum = target; sum >= num; sum--) {
                // select or not select
                dp[sum] = dp[sum] || dp[sum - num];
            }

            if (dp[target]) return true;
        }

        return dp[target];

    }
};
