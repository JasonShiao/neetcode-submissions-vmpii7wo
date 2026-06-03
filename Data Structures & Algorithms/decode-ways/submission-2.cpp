class Solution {
public:
    int numDecodings(string s) {
        // case 2: if combo, the next can only be 0-6
        // case 1
        // case 3-9
        // case 0: cannot be alone (must follow a non-zero)

        // # of ways start from idx = 
        //   # of ways start from the (idx+1) + 
        //   # of ways start from the (idx+2)

        if (s.length() == 0) {
            return 0;
        }

        // -> DP and iterate from back of s
        int dp[2] = {0, 1};
        if (s[s.length()-1] == '0') {
            dp[0] = 0;
        } else {
            dp[0] = 1;
        }

        // # possible ways starting from idx
        for (int idx = s.length() - 2; idx >= 0; idx--) {
            int tmp = 0;
            if (s[idx] == '0') {
                tmp = 0;
            } else if (s[idx] == '2') {
                if (s[idx+1] - '0' > 6) {
                    tmp = dp[0]; // start from idx+1
                } else if (s[idx+1] == '0') {
                    tmp = dp[1];
                } else {
                    tmp = dp[0] + dp[1];
                }
            } else if (s[idx] == '1'){
                // could have combo
                if (s[idx+1] == '0') { // only combo
                    tmp = dp[1];
                } else {
                    tmp = dp[0] + dp[1];
                }
            } else { // 3-9: no combo
                if (s[idx+1] == '0') { 
                    // no way: combo invalid, separate invalid
                    tmp = 0;
                } else {
                    tmp = dp[0];
                }
            }

            // push tmp into dp
            dp[1] = dp[0];
            dp[0] = tmp;
        }

        return dp[0];

    }
};
