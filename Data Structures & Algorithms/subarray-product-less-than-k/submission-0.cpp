class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // without 0, keep inc r and inc l
        // when encouters 0, count all on the left
        int res = 0;
        long long curr_prod = 1;
        int l = 0; // Key: maintain l so that no 0 between [l, r]
        int last_zero_pos = -1;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] != 0) {
                curr_prod *= nums[r];
                while (l <= r && curr_prod >= k) {
                    curr_prod /= nums[l];
                    l++;
                }
                if (curr_prod < k) {
                    res += (r - l + 1);
                    if (k > 0 && last_zero_pos != -1) {
                        // add all windows that starts before last zero pos
                        res += (last_zero_pos + 1);
                    }
                }
            } else {
                if (k > 0) {
                    res += (r + 1); // all the windows ends at r which is 0
                }
                last_zero_pos = r;
                l = last_zero_pos + 1;
            }
        }

        return res;
    }
};