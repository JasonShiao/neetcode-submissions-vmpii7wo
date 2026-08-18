class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_len = 0;
        int curr_len = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (curr_len == 0) {
                curr_len += 1;
                max_len = max(max_len, curr_len);
            } else if (curr_len == 1) {
                if (nums[i] == nums[i-1]) {
                    // invalid -> not strictly dec/inc
                    curr_len = 1; // reset the subarray
                } else {
                    curr_len += 1;
                    max_len = max(max_len, curr_len);
                }
            } else { // more than 2 elements -> must determine inc/dec
                if (nums[i-1] > nums[i-2]) {
                    // inc
                    if (nums[i] > nums[i-1]) {
                        curr_len += 1;
                        max_len = max(max_len, curr_len);
                    } else if (nums[i] == nums[i-1]) {
                        curr_len = 1; // reset
                    } else {
                        // NOTICE: be careful of this case
                        curr_len = 2; // become a dec array of 2
                    }
                } else {
                    // dec
                    if (nums[i] < nums[i-1]) {
                        curr_len += 1;
                        max_len = max(max_len, curr_len);
                    } else if (nums[i] == nums[i-1]) {
                        curr_len = 1; // reset
                    } else {
                        // NOTICE: be careful of this case
                        curr_len = 2; // become a inc array of 2
                    }
                }
            }
        }

        return max_len;
    }
};