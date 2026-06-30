class Solution {
public:
    void reverseWords(vector<char>& s) {
        // Tricks: 
        //   Reverse entire and then reverse partial
        //   NOTE: can also be used to shift a ring buffer

        // 1. Revserse entire s
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l += 1;
            r -= 1;
        }

        // 2. Reverse each space separated word (whose char are reversed by previous step)
        l = 0;
        int word_sep_pos = 0;
        while (word_sep_pos <= s.size()) {
            if (word_sep_pos == s.size() || 
                s[word_sep_pos] == ' ') {
                
                // reverse the word
                r = word_sep_pos - 1;

                while (l < r) {
                    char tmp = s[l];
                    s[l] = s[r];
                    s[r] = tmp;
                    l += 1;
                    r -= 1;
                }

                // remember to update l
                l = word_sep_pos + 1;
            }
            word_sep_pos += 1;
        }
    }
};
