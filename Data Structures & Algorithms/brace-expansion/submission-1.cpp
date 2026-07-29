class Solution {
public:
    void backtrack(const string& s, int idx, string& tmp, vector<string>& res) {
        if (idx == s.length()) {
            // finish a string: push to res and return immediately
            res.push_back(tmp);
            return;
        }

        // select from multiple or only one option
        if (s[idx] == '{') {
            // search for '}' and build the options at the same time
            int cur = idx + 1;
            vector<char> options;
            while (s[cur] != '}') {
                if (s[cur] != ',') {
                    options.push_back(s[cur]);
                }
                cur += 1;
            }
            // try each option for backtracking branch
            for (auto opt: options) {
                tmp += opt;
                backtrack(s, cur + 1, tmp, res);
                // recover for the next branch
                tmp = tmp.substr(0, tmp.length() - 1);
            }
        } else {
            // only one option
            tmp += s[idx];
            backtrack(s, idx + 1, tmp, res);
            // recover for upper
            tmp = tmp.substr(0, tmp.length() - 1);
        }
    }

    vector<string> expand(string s) {
        vector<string> res;
        string tmp = "";
        backtrack(s, 0, tmp, res);
        return res;
    }
};
