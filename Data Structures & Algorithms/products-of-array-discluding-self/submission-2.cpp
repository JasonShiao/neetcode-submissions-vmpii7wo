class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Approach 1: div i-1 and mult i

        // Approach 2: prefix-prod and suffix prod
        // prefix[i]: prefix mult for "indices < i"
        // suffix[j]: suffix mult for "indices > n-j-1"

        // given an index k
        // i for prefix = k
        // j for suffix = n - k -1
        //    k = n-j-1 -> j = n - k - 1
        vector<int> prefix_mult = {1};
        int cummulative_prefix = 1;
        vector<int> suffix_mult = {1};
        int cummulative_suffix = 1;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cummulative_prefix *= nums[i];
            prefix_mult.push_back(cummulative_prefix);
        }

        // suffix mult [i] == cummulative mult include (n - 1 - i)
        for (int i = n-1; i >= 0; i--) {
            cummulative_suffix *= nums[i];
            suffix_mult.push_back(cummulative_suffix);
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(prefix_mult[i] * suffix_mult[n - i - 1]);
        }
        return res;
    }
};
