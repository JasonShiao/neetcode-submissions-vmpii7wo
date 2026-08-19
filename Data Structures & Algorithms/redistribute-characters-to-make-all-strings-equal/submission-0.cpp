class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // count all chars
        // check if each char cnt is divisible by words.size()
        vector<int> char_cnt(26, 0);
        for (auto word: words) {
            for (auto c: word) {
                char_cnt[c - 'a'] += 1;
            }
        }
        int n = words.size();
        for (int i = 0; i < 26; i++) {
            if (char_cnt[i] % n) {
                return false;
            }
        }
        return true;
    }
};