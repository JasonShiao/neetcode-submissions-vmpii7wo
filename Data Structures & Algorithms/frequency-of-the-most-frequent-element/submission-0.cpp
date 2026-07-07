class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        // key 1: can only increment value
        
        // 1. sort for convenience
        sort(nums.begin(), nums.end());

        // Key: prioritize the element smaller and closest to nums[i]
        // 2. only look to the left of curr idx
        int max_freq = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr_freq = 1;
            int curr_op_required = 0;
            int j = i - 1;
            // O(k) for the while loop -> could be further optimized
            while (j >= 0) {
                curr_op_required += abs(nums[i] - nums[j]);
                if (curr_op_required > k) {
                    break;
                }
                curr_freq += 1;
                j -= 1;
            }
            max_freq = max(max_freq, curr_freq);
        }

        return max_freq;
    }
};