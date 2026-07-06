class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        // 1. sort
        sort(nums.begin(), nums.end());

        // 2. Critical: How to reject (skip) duplicate?
        for (int i = 0; i < nums.size() - 1; i++) {
            // no dup check for first (i.e. i = 0)
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i+1; j < nums.size() - 1; j++) {
                // no dup check for first (i.e. j = i+1)
                if (j > i+1 && nums[j] == nums[j - 1]) continue;

                // Critical: handle integer overflow
                long long partial_target = (long long)target - nums[i] - nums[j];

                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    if (nums[k] + nums[l] > partial_target) {
                        l -= 1;
                    } else if (nums[k] + nums[l] < partial_target) {
                        k += 1;
                    } else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k += 1;
                        l -= 1;
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }

        return res;
    }
};