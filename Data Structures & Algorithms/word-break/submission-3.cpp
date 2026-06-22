class Solution {
public:
    bool dfs(const string& s, int idx, 
                vector<string>& wordDict, 
                unordered_set<int>& failed) {
        if (idx == s.length()) {
            return true;
        }

        if (failed.find(idx) != failed.end()) {
            return false;
        }

        // Check all branches (words in dict)
        for (auto word: wordDict) {
            if (s.substr(idx, word.length()) == word) {
                if (dfs(s, idx + word.length(), wordDict, failed)) {
                    return true;
                }
            }
        }

        failed.insert(idx);
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Like a puzzle game but with inf number of each piece

        // DFS + DP
        // NOTE: DP is used for filtering out some duplicate cases

        unordered_set<int> failed;
        return dfs(s, 0, wordDict, failed);
    }
};
