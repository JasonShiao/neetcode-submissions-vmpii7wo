class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 1. hash table approach -> O(n) space required
        unordered_map<int, int> val_cnt;
        for (auto& num: nums) {
            if (val_cnt.find(num) != val_cnt.end()) {
                val_cnt[num] += 1;
            } else {
                val_cnt[num] = 1;
            }
            if (val_cnt[num] > nums.size() / 2) {
                return num;
            }
        }
        return -1;

    }
};