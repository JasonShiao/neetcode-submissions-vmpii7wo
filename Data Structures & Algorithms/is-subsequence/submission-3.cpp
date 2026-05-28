class Solution {
public:
    bool isSubsequence(string s, string t) {
        // time: O(n^2)
        for (int i = 0; i < t.length(); i++) {
            // slow and fast pointer
            // new start position
            int s_cursor = 0;
            int t_cursor = i;
            
            while (s_cursor < s.length() && 
                    t_cursor < t.length()) {
                if (s[s_cursor] == t[t_cursor]) {
                    s_cursor++;
                }
                t_cursor++;
            }
            if (s_cursor == s.length()) {
                return true;
            }
        }
        return false;
    }
};