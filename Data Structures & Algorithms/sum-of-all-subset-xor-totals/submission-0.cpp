class Solution {
public:
    void backtrack(vector<int>& nums, int idx, int& sum, int cur_xor) {
        // only add to sum when a subset is complete
        if (idx == nums.size()) {
            sum += cur_xor;
            return;
        }

        int exclude_xor = cur_xor;
        backtrack(nums, idx + 1, sum, exclude_xor);
        int include_xor = cur_xor ^ nums[idx];
        backtrack(nums, idx + 1, sum, include_xor);

        return;
    }

    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int cur_xor = 0;
        backtrack(nums, 0, sum, cur_xor);

        return sum;
    }
};