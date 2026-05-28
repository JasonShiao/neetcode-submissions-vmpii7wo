class Solution {
public:
    int scoreOfString(string s) {
        int res = 0;

        // a little bit like sliding window
        for (int i = 0; i < (s.length() - 1); i++) {
            res += abs(s[i] - s[i+1]);
        }

        return res;
    }
};