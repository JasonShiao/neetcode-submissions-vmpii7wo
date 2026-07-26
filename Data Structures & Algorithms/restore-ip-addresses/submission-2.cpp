class Solution {
public:
    bool is_valid(const string& s) {
        int val = 0;
        int cursor = 0;
        // handle leading 0 cases
        if (s.length() > 1 && s[0] == '0') {
            return false;
        } else if (s.length() > 3) {
            return false;
        }
        while (cursor < s.length()) {
            val *= 10;
            val += (s[cursor] - '0');
            cursor += 1;
        }
        return val < 256;
    }
    void backtrack(const string& s, int cursor,
                int num_dot_remain, string& curr,
                vector<string>& res) {
        if (cursor >= s.length()) {
            return;
        }
        if (num_dot_remain == 0) {
            // the last part: validate and push to result
            // validate from cursor to the end in string s
            if (is_valid(s.substr(cursor))) {
                string new_possib = curr + s.substr(cursor);
                res.push_back(new_possib);
            }
            return;
        } else {
            for (int i = 1; i <= 3; i++) {
                if (is_valid(s.substr(cursor, i))) {
                    string new_possib = curr + s.substr(cursor, i) + ".";
                    backtrack(s, cursor + i, num_dot_remain - 1, new_possib, res);
                }
            }
        }


    }

    vector<string> restoreIpAddresses(string s) {
        // Approach 1: nested for loop
        // vector<string> res;
        // for (int i = 1; i <= s.length(); i++) {
        //     if (!is_valid(s.substr(0, i))) {
        //         break;
        //     }
        //     for (int j = i + 1, j <= s.length(); j++) {
        //         if (!is_valid(s.substr(i, j))) {
        //             break;
        //         }
        //         for (int k = j + 1; k <= s.length(); k++) {
        //             if (is_valid(s.substr(j, k)) && 
        //                 is_valid(s.substr(k))) {
        //                 res.push_back(...);
        //             }
        //         }
        //     }
        // }

        // Approach 2: Backtracking
        string curr = "";
        vector<string> res;
        backtrack(s, 0, 3, curr, res);

        return res;
    }
};