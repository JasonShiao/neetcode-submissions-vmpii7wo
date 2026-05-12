class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool> lookup(nums.size(), false);
        for (auto& num: nums) {
            if (lookup[num]) {
                return num;
            } else {
                lookup[num] = true;
            }
        }
    }
};
