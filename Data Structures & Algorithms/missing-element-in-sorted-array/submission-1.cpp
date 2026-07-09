class Solution {
public:
    int missing(vector<int>& nums, int i) {
        return nums[i] - nums[0] - i;
    }
    int missingElement(vector<int>& nums, int k) {
        // 1. linear search O(n)
        // 2. binary search O(log n)
        // handle special case here
        // kth missing is after r
        int n = nums.size();
        if (missing(nums, n-1) < k) {
            return nums[n - 1] + (k - missing(nums, n-1));
        }

        int r = nums.size() - 1;
        int l = 0;

        while (l < r) {
            int m = (l + r) / 2;
            // check missing "till" m
            if (missing(nums, m) < k) {
                // on the right half
                l = m + 1;
            } else {
                // on the left half
                r = m;
            }
        }

        // l is first index where missing(l) >= k
        return nums[l - 1] + (k - missing(nums, l - 1));
    }
};
