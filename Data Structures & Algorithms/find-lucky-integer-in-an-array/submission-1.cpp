class Solution {
public:
    int findLucky(vector<int>& arr) {
        // hash map for val cnt
        unordered_map<int, int> val_cnt;
        for (auto val: arr) {
            val_cnt[val] += 1;
        }

        // find the match and maintain the max freq
        int max_cnt = -1;
        for (auto [val, cnt]: val_cnt) {
            if (val == cnt) {
                max_cnt = max(max_cnt, val);
            }
        }
        return max_cnt;
    }
};