class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix_sum;
        int current_sum = 0;
        for (auto num: nums) {
            current_sum += num;
            prefix_sum.push_back(current_sum);
        }

        for (int i = 0; i < nums.size(); i++) {
            // check left sum and right sum
            int left_sum = (i == 0 ? 0 : prefix_sum[i - 1]);
            int right_sum = (i == (nums.size() - 1) ? 
                        0 : prefix_sum[nums.size()-1] - prefix_sum[i]);
            if (left_sum == right_sum) {
                return i;
            }
        }

        // pivot not found
        return -1;
    }
};