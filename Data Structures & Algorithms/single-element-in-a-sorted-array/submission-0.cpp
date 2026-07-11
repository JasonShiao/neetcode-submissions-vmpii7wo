class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // non-sorted -> use XOR -> O(n)
        // sorted -> binary search -> O(log n)
    
        int r = nums.size() - 1;
        int l = 0;
        while (l < r) {
            int m = (r + l) / 2;
            if (nums[m] == nums[m+1]) {
                if ((m+1 - l + 1) % 2) { // odd in the left
                    r = m - 1;
                } else {
                    l = m + 2;
                }
            } else if (nums[m] == nums[m-1]) {
                if ((m - l + 1) % 2) { // odd in the left
                    r = m - 2;
                } else {
                    l = m + 1;
                }
            } else {
                return nums[m];
            }
        }

        return nums[l];

    }
};