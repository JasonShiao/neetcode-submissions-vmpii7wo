class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        // find max in nums for n
        int n = 0;
        for (int num: nums) {
            if (num > n) {
                n = num;
            }
        }
        // special case: [0,...,n-1] -> n is missing
        if (n < nums.size()) {
            return nums.size();
        }

        // Method 1:
        // Do it for [0, n] and nums:
        //   Equivalent to XOR for a array with dup pair values 
        //   and only one element is non dup
        // for (int i = 0; i <= n; i++) {
        //     result ^= i;
        // }
        // for (int num: nums) {
        //     result ^= num;
        // }

        // Method 2:
        // calc sum([0, n]) - sum(nums)
        int expected_sum = n * (n+1) / 2;
        int sum_nums = accumulate(nums.begin(), nums.end(), 0);
        result = expected_sum - sum_nums;

        return result;
    }
};
