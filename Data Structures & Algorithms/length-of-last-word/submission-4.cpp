class Solution {
public:
    int lengthOfLastWord(string s) {
        int last_word_len = 0;

        // edge case: space(s) at the end -> ignore them (trim)

        for (int i = (s.length() - 1); i >= 0; i--) {
            if (s[i] == ' ') {
                if (last_word_len == 0) {
                    // no word detected yet -> keep going
                } else {
                    // a non-empty word has been detected
                    break; // need to break immediately
                }
            } else {
                // char in word
                last_word_len += 1;
            }

        }

        return last_word_len;
    }
};