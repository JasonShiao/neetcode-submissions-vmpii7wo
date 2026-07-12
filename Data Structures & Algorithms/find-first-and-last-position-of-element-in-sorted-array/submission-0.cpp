class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Boundary search for both edge

        // Lower bound
        int l = 0;
        int r = nums.size() - 1;
        int lower_bound = INT_MAX;
        while (l <= r) {
            int m = (r + l) / 2;
            if (nums[m] < target) {
                // search right
                l = m + 1;
            } else if (nums[m] > target) {
                // search left
                r = m - 1;
            } else { // search for lower
                // search left
                r = m - 1; // r dec at least by 1
                lower_bound = min(lower_bound, m);
            }
        }

        if (lower_bound == INT_MAX) {
            return {-1, -1};
        }

        int upper_bound = -1;
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            int m = (r + l) / 2;
            if (nums[m] < target) {
                // search right
                l = m + 1;
            } else if (nums[m] > target) {
                // search left
                r = m - 1;
            } else { // search for end
                // search right
                l = m + 1; // l inc at least by 1
                upper_bound = max(upper_bound, m);
            }
        }

        return {lower_bound, upper_bound};
    }
};