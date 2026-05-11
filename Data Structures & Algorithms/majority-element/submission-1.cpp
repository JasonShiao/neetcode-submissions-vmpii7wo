class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 1. hash table approach -> O(n) space required
        // unordered_map<int, int> val_cnt;
        // for (auto& num: nums) {
        //     if (val_cnt.find(num) != val_cnt.end()) {
        //         val_cnt[num] += 1;
        //     } else {
        //         val_cnt[num] = 1;
        //     }
        //     if (val_cnt[num] > nums.size() / 2) {
        //         return num;
        //     }
        // }
        // return -1;

        // 2. Boyer–Moore Voting Algorithm: O(1) space, Linear time
        int cnt = 1;
        int cand_val = nums[0];
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] == cand_val) {
                cnt += 1;
            } else {
                cnt -= 1;
                if (cnt < 0) {
                    cnt = 1;
                    cand_val = nums[i];
                }
            }
        }
        return cand_val;
    }
};