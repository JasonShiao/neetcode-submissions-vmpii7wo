class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = nums.size() + 1;

        int window_sum = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            // update window with new r
            window_sum += nums[r];
            while (window_sum >= target) {
                min_len = min(min_len, r - l + 1);
                // move left pointer, update window sum
                window_sum -= nums[l];
                l += 1;
            }
        }

        // margin case
        if (min_len == nums.size() + 1) {
            return 0;
        }

        return min_len;
    }
};