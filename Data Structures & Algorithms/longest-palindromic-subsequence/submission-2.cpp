class Solution {
private:
    // memoization lookup
    // Critical point: use vector<vector<int>> instead of map to improve performance
    //map<pair<int, int>, int> dp_lookup; // {l, r} -> length of longest common subseq
    vector<vector<int>> dp_lookup; // dp_lookup[l][r] -> length of longest common subseq
public:
    int dfsHelper(int l, int r, string s) {
        // DFS + memoization
        if (l < 0 || r >= s.length()) {
            return 0;
        }

        if (dp_lookup[l][r] != -1) {
            return dp_lookup[l][r];
        }
        // if (dp_lookup.find({l, r}) != dp_lookup.end()) {
        //     return dp_lookup[{l, r}];
        // }

        if (s[l] == s[r]) {
            if (l == r) {
                dp_lookup[l][r] = 1 + dfsHelper(l-1, r+1, s);
                //dp_lookup[{l, r}] = 1 + dfsHelper(l-1, r+1, s);
            } else {
                dp_lookup[l][r] = 2 + dfsHelper(l-1, r+1, s);
                //dp_lookup[{l, r}] = 2 + dfsHelper(l-1, r+1, s);
            }
        } else {
            dp_lookup[l][r] = max(dfsHelper(l-1, r, s), 
                dfsHelper(l, r+1, s));
            //dp_lookup[{l, r}] = max(dfsHelper(l-1, r, s), 
            //    dfsHelper(l, r+1, s));
        }

        return dp_lookup[l][r];
        //return dp_lookup[{l, r}];
    }

    int longestPalindromeSubseq(string s) {
        dp_lookup = vector<vector<int>>(s.length(), 
            vector<int>(s.length(), -1));
        // modified LCS problem
        // 1. same as normal longest Palindrome search
        //   separate odd and even length cases
        int max_length = 0;
        for (int i = 0; i < s.length(); i++) {
            // 1. odd
            int odd_longest = dfsHelper(i, i, s);
            if (odd_longest > max_length) {
                max_length = odd_longest;
            }
            // 2. even
            int even_longest = dfsHelper(i, i+1, s);
            if (even_longest > max_length) {
                max_length = even_longest;
            }
        }

        return max_length;
    }
};