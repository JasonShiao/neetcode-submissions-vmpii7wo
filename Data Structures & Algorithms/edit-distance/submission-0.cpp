class Solution {
private:
    vector<vector<int>> dp;
public:
    // return the total op count starting from i and j resp.
    int recursive(string& word1, int i, string& word2, int j) {
        // terminate condition
        if (i == word1.size()) {
            return word2.size() - j;
        }
        if (j == word2.size()) {
            return word1.size() - i;
        }

        // dp to skip duplicate case
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // simple match case
        if (word1[i] == word2[j]) {
            return recursive(word1, i + 1, word2, j + 1);
        }

        // mismatch -> 3 branches
        int res = INT_MAX;
        // insert (i remain the same while j inc)
        res = min(res, recursive(word1, i, word2, j + 1) + 1);
        // remove (i inc while j remain the same)
        res = min(res, recursive(word1, i + 1, word2, j) + 1);
        // replace
        res = min(res, recursive(word1, i + 1, word2, j + 1) + 1);

        dp[i][j] = res; // update dp
        return res;
    }

    int minDistance(string word1, string word2) {
        // Idea: For each mismatch char 
        //     -> 3 branches, insert/delete/replace char to word1
        dp = vector<vector<int>>(word1.size(), 
                vector<int>(word2.size(), -1));
        return recursive(word1, 0, word2, 0);
    }
};
