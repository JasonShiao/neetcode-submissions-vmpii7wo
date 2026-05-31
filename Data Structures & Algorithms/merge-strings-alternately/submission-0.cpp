class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int cur = 0;
        while (cur < word1.length() || cur < word2.length()) {
            if (cur < word1.length()) {
                res += word1[cur];
            }
            if (cur < word2.length()) {
                res += word2[cur];
            }
            cur += 1;
        }


        return res;
    }
};