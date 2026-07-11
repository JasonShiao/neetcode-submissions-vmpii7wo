class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Linear search O(n): trivial
        // Binary search: not intuitive!

        // Key concern: How to handle plateau? 
        //    -> The constraints have eliminated this condition!!!
        //       nums[i] != nums[i+1] for all i
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int m = (l + r) / 2;
            if ((m == nums.size() - 1) || nums[m+1] > nums[m]) {
                l = m + 1;
            } else if (m == 0 || nums[m-1] > nums[m]) {
                r = m - 1;
            } else {
                // nums[m] > nums[m-1] && nums[m] > nums[m+1]
                return m;
            }
        }

        return l;
    }
};