class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> window;
        int res = 0;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            window[s[r]] += 1;
            if (window.size() > 2) { // more than 2 keys -> must remove one
                // move l (and dec char cnt) until no dup
                while (l < r && window.size() > 2) {
                    window[s[l]] -= 1;
                    if (window[s[l]] == 0) {
                        window.erase(s[l]);
                    }
                    l++;
                }
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};