class Solution {
public:
    int firstUniqChar(string s) {
        // store char state
        // -1: not occur, -2: occur more than once
        // >= 0: position (if occur once)
        vector<int> char_state(26, -1);
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (char_state[c - 'a'] == -1) {
                char_state[c - 'a'] = i;
            } else if (char_state[c - 'a'] == -2) {
                // ignore
            } else {
                // already appear once -> move to -2
                char_state[c - 'a'] = -2;
            }
        } 

        // examine and find the min
        int first_non_dup = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (char_state[i] >= 0) {
                // Caveat: candidate, might not be the first!!!
                first_non_dup = min(first_non_dup, char_state[i]);
            }
        }
        return first_non_dup == INT_MAX ? -1 : first_non_dup;
    }
};