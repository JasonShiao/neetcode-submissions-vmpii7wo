class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // i.e. Find the largest window with at most k zeroes
        int res = 0;
        int window = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                window += 1;
            }
            // make window valid
            while (window > k) {
                if (nums[l] == 0) {
                    window -= 1;
                }
                l++;
            }
            // update with the new valid window
            res = max(res, r - l + 1);
        }

        return res;
    }
};