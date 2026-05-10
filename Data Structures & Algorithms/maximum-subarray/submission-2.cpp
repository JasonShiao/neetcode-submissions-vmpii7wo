class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = -1000;
        int curr_sum = 0;
        // curr_sum = max subarray sum of first i-1 (MUST including i-1)
        // check if a < 0
        // -> yes, not include curr_sum -> curr_sum = nums[i]
        // -> no, include curr_sum -> curr_sum = nums[i] + curr_sum
        for (int num: nums) {
            if (curr_sum < 0) {
                curr_sum = 0;
            }
            curr_sum += num;
            max_sum = max(curr_sum, max_sum);
        }

        return max_sum;

    }
};
