class Solution {
public:
    // min of max sum of m partition (starting from idx i)
    int dfs(vector<int>& nums, 
            map<pair<int,int>, int>& dp, // (i,m) -> max sum
            int i, int m) {
        if (m == 1) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
            }
            return sum;
        } else if (dp.find({i, m}) != dp.end()) {
            return dp[{i,m}];
        }

        int cur_sum = 0;
        int min_max_sum = INT_MAX;
        for (int j = i; j <= nums.size() - m; j++) {
            cur_sum += nums[j];
            int max_sum = max(cur_sum, dfs(nums, dp, j+1, m-1));
            min_max_sum = min(min_max_sum, max_sum);
        }
        dp[{i, m}] = min_max_sum;

        return min_max_sum;

    }

    int splitArray(vector<int>& nums, int k) {
        map<pair<int,int>, int> dp;

        return dfs(nums, dp, 0, k);
    }
};