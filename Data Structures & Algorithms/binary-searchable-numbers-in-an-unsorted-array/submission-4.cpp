class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        // Any reverse order pair -> cannot be removed

        // suffix -> largest value to the left (exclude i)
        // prefix -> smallest value to the right (exclude i)
        vector<int> max_left;
        int cur_max = -100001;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            max_left.push_back(cur_max);
            if (*it > cur_max) {
                cur_max = *it;
            }
        }
        vector<int> min_right(nums.size(), 100001);
        int cur_min = 100001;
        for (int i = nums.size() - 1; i >= 0; i--) {
            min_right[i] = cur_min;
            if (nums[i] < cur_min) {
                cur_min = nums[i];
            }
        }

        // For each value, check whether left max < nums[i] && nums[i] < right min
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (max_left[i] < nums[i] && nums[i] < min_right[i]) {
                // correct order -> can be found
                res += 1;
            }
        }

        return res;
    }
};
