class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        // whenever a lower value encountered -> reset the current sum
        int max_sum = nums[0];
        int curr_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i-1]) {
                // reset
                curr_sum = nums[i];
            } else {
                curr_sum += nums[i];
                max_sum = max(max_sum, curr_sum);
            }
        }

        return max_sum;
    }
};