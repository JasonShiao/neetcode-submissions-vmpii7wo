class Solution {
public:
    void backtrack(int idx, int n, string& tmp,
            vector<string>& res) {
        // if n > 1, candidate digit pair: (0, 0), (1, 1), (6, 9), (8, 8), (9, 6)
        // if n == 1, candidate digit: 0, 1, 8
        if (idx >= n) {
            // finished: exclude the case starting with 0
            if (n == 1 || tmp[0] != '0') {
                res.push_back(tmp);
            }
            return;
        }
        if ((idx == n / 2) && (n % 2)) {
            // the center of a odd length
            const vector<char> cand_list = {'0', '1', '8'};
            for (auto c: cand_list) {
                tmp += c;
                backtrack(idx + 1, n, tmp, res);
                tmp = tmp.substr(0, tmp.length() - 1);
            }
            return;
        }
        // non center of an odd length string -> a pair of digit is added
        const vector<pair<char, char>> cand_pairs = {
            {'0', '0'}, {'1', '1'}, {'6', '9'},
            {'8', '8'}, {'9', '6'},
        };
        for (auto digit_pair: cand_pairs) {
            tmp = digit_pair.first + tmp;
            tmp += digit_pair.second;
            backtrack(idx + 1, n, tmp, res);
            // recover
            tmp = tmp.substr(1, tmp.length() - 2);
        }
    }
    vector<string> findStrobogrammatic(int n) {
        // if n > 1, MUST remove the string starting with '0'!
        vector<string> res;
        string tmp = "";
        // build string from inner!!
        backtrack(n/2, n, tmp, res);

        return res;
    }
};
