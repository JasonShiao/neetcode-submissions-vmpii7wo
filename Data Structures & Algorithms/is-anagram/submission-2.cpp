class Solution {
public:
    bool isAnagram(string s, string t) {
        // use a hash map
        unordered_map<char, int> char_cnt;
        for (auto c: s) {
            char_cnt[c] += 1;
        }
        for (auto c: t) {
            char_cnt[c] -= 1;
        }

        // check if any < 0
        for (auto [key, val]: char_cnt) {
            if (val < 0 || val > 0) {
                return false;
            }
        }


        return true;
    }
};
