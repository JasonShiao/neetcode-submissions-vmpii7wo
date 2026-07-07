class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> window; // char_cnt

        // edge case: k = 0
        if (k == 0) { // Critical!!!
            return 0;
        }
        // edge case: s.length() == 0 or 1

        int max_window = 0;
        int l = 0; // each [l,r] must be a valid window
        for (int r = 0; r < s.length(); r++) {
            window[s[r]] += 1;
            if (window.size() > k) { // k distinct chars (keys)
                // move l until <= k keys
                while (l < r && window.size() > k) {
                    window[s[l]] -= 1;
                    if (window[s[l]] == 0) { // MUST remove key manually!!
                        window.erase(s[l]);
                    }
                    l++;
                }
            }
            // check the new valid window
            max_window = max(max_window, r - l + 1);
        }

        return max_window;
    }
};
