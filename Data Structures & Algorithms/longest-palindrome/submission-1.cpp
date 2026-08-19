class Solution {
public:
    int longestPalindrome(string s) {
        // at most one odd cnt char

        // any even char cnt -> include unconditionally
        // for odd char cnt -> use the max cnt

        // Caveat: the odd cnt char can still be used (partially)!!!

        unordered_map<char, int> char_cnt;
        for (auto c: s) {
            char_cnt[c] += 1;
        } 

        // check char cnt
        int length = 0;
        bool odd_exist = 0;
        for (auto [c, cnt]: char_cnt) {
            if (cnt % 2 == 0) {
                length += cnt;
            } else {
                length += cnt - 1; // make it even cnt
                odd_exist = true;
            }
        }

        if (odd_exist) length += 1;

        return length;
    }
};