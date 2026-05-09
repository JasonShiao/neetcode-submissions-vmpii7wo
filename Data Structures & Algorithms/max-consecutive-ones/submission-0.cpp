class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_len = 0;
        int max_len = 0;
        // add one extra 0 to make it easier handle the last consecutive 1's
        nums.push_back(0);
        for (auto& num: nums) {
            if (num == 1) {
                curr_len += 1;
            } else {
                if (curr_len > max_len) {
                    max_len = curr_len;
                }
                curr_len = 0;

            }
        }

        return max_len;
    }
};