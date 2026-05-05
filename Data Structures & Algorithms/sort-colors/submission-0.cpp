class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> bucket{0, 0, 0};

        for (auto& num: nums) {
            bucket[num] += 1;
        }

        int cur = 0;
        for (auto i = 0; i < bucket.size(); i++) {
            for (auto j = 0; j < bucket[i]; j++) {
                nums[cur] = i;
                cur += 1;
            }
        }
    }
};