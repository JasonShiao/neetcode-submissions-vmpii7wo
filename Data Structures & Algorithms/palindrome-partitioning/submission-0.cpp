class Solution {
public:
    bool check_palindrome(const string& s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void backtrack(string s, int idx, vector<string>& cand,
                    vector<vector<string>>& res) {
        if (idx == s.length()) {
            // check cand_list and add to res
            if (check_palindrome(cand[cand.size()-1])) {
                res.push_back(cand);
            }
            return;
        }

        // belong to prev group
        if (!cand.empty()) {
            cand[cand.size()-1] += s[idx];
            backtrack(s, idx+1, cand, res);
            // recover
            cand[cand.size()-1].pop_back();
        }

        // create a new group
        // Should check if prev group is palindrome
        if (cand.empty() || check_palindrome(cand[cand.size()-1])) {
            cand.push_back(string(1, s[idx]));
            backtrack(s, idx+1, cand, res);
            // recover
            cand.pop_back();
        }

    }

    vector<vector<string>> partition(string s) {
        // each char has two options: 
        // 1. belongs to the previous group (no cut right before idx) or 
        // 2. create a new group (a cut right before idx)
        vector<vector<string>> res;
        vector<string> cand;
        backtrack(s, 0, cand, res);

        return res;
    }
};
