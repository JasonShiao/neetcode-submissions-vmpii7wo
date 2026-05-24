class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // use a set to represent window info
        unordered_set<char> window_set;
        int l = 0;
        int r = 0;
        int longest_len = 0;
        int cur_len = 0;
        while (r < s.length()) {
            if (window_set.find(s[r]) != window_set.end()) {
                // move l until the dup is removed
                while (l < r && window_set.find(s[r]) != window_set.end()) {
                    window_set.erase(s[l]);
                    l++;
                }
            }
            window_set.insert(s[r]);
            if (r - l + 1 > longest_len) {
                longest_len = r - l + 1;
            }
            r++;
        }

        return longest_len;
    }
};
