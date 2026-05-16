class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_sum_cnt;

        prefix_sum_cnt[0] = 1; // set initial cnt 1 for sum to 0
        int accum_sum = 0;
        int res = 0;
        for (auto& num: nums) {
            accum_sum += num;

            if (prefix_sum_cnt.find(accum_sum - k) != prefix_sum_cnt.end()) {
                // found match: update res
                // always include the current num
                //  -> search the number of ways to start the subarray and sum to k
                res += prefix_sum_cnt[accum_sum - k];
            } else {
                // not found match: do nothing
            }

            if (prefix_sum_cnt.find(accum_sum) == prefix_sum_cnt.end()) {
                prefix_sum_cnt[accum_sum] = 1;
            } else {
                prefix_sum_cnt[accum_sum] += 1;
            }
        }
        return res;
    }
};