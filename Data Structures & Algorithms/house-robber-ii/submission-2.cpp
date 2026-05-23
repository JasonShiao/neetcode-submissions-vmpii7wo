class Solution {
public:
    int robLinear(vector<int>& nums, int l, int r) {
        int prev2 = 0;
        int prev1 = 0;

        // can select or not select i
        for (int i = l; i <= r; i++) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        // separate two cases:
        return max(
            robLinear(nums, 0, n - 2), // include first, exclude last
            robLinear(nums, 1, n - 1)  // exclude first, include last
        );
    }
};
