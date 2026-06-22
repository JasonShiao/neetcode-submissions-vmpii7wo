class Solution {
public:
    bool backtrack(const string& s, int idx, 
                vector<string>& wordDict, 
                unordered_set<int>& checked) {
        if (idx == s.length()) {
            return true;
        }

        if (checked.find(idx) != checked.end()) {
            return false;
        }

        // Check all branches (words in dict)
        for (auto word: wordDict) {
            if (s.substr(idx, word.length()) == word) {
                if (backtrack(s, idx + word.length(), wordDict, checked)) {
                    return true;
                } else {
                    // mark as checked
                    checked.insert(idx+word.length());
                }
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Like a puzzle game but with inf number of each piece

        // DFS + DP
        // NOTE: DP is used for filtering out some duplicate cases

        unordered_set<int> checked;
        return backtrack(s, 0, wordDict, checked);
    }
};
