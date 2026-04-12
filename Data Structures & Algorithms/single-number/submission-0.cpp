class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // hint: multiple XOR operation, the order doesn't matter
        // the value XOR with itself = 0
        // after XOR all values, the remaining result is the only one without pair
        int result = 0;
        for (int num: nums) {
            result ^= num;
        }
        return result;
    }
};
