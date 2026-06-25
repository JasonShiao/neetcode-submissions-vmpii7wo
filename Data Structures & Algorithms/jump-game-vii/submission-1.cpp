class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> dp(s.length(), false);
        dp[0] = true;

        for (int i = 1; i < s.length(); i++) {
            // forbidden pos
            if (s[i] != '0') {
                // dp[i] already preset to false
                continue;
            }
            // possible but require further check
            for (int j = minJump; j <= maxJump; j++) {
                if (i - j < 0) {
                    break;;
                }
                if (dp[i - j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length() - 1];
    }
};