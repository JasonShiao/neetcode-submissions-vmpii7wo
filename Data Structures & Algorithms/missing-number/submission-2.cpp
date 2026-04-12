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
        if (n < nums.size()) {
            return nums.size();
        }

        for (int i = 0; i <= n; i++) {
            result ^= i;
        }
        for (int num: nums) {
            result ^= num;
        }
        return result;
    }
};
