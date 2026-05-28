class Solution {
public:
    int appendCharacters(string s, string t) {
        // Key idea: the required # chars for substring >= the required # chars for entire string
        //  thus, we always start from index 0 to check

        // t be a subsequence of s -> s must contain all chars in t following the order
        int s_cur = 0;
        int t_cur = 0;
        while (true) {
            if (s_cur >= s.length()) {
                // append the remaining char of t to s
                return t.length() - t_cur;
            } else if (t_cur >= t.length()) {
                return 0; // no char append needed
            } else if (s[s_cur] == t[t_cur]) {
                // inc both
                s_cur++;
                t_cur++;
            } else {
                // inc s only
                s_cur++;
            }
        }

    }
};