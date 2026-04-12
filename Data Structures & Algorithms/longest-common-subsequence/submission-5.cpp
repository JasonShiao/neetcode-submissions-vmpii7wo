class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(); // rows
        int n = text2.length(); // cols

        vector<int> dp(n+1, 0);
        for(int i = m-1; i >= 0; i--) {
            int diag_lower_right = 0; // store cell 3
            // Need two cells from prev row and one cell from current row
            // curr_cell  |  cell 1
            // --------------------
            //  cell 2    |  cell 3
            for (int j = n - 1; j >= 0; j--) {
                // NOTICE: don'f forget to store the curr cell
                // store and use un-updated curr as diag for the next cell
                int prev = dp[j];
                
                // update in place
                if (text1[i] == text2[j]) {
                    dp[j] = diag_lower_right + 1; // diagonal + 1
                } else {
                    dp[j] = max(dp[j], dp[j+1]); // max from (down, right)
                }

                // un-updated curr cell is used as diag for the next cell
                diag_lower_right = prev; 
            }
        }
        return dp[0];

    }
};
