class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = -1000;
        int curr_sum = 0;
        for (int num: nums) {
            if (curr_sum < 0) {
                curr_sum = 0;
            }
            curr_sum += num;
            max_sum = max(curr_sum, max_sum);
        }

        return max_sum;

    }
};
