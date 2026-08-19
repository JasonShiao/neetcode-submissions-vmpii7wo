class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        // select the largest 2 element
        // select the smallest 2 element

        sort(nums.begin(), nums.end());
        return nums[nums.size() - 1] * nums[nums.size() - 2] - nums[0] * nums[1];
    }
};