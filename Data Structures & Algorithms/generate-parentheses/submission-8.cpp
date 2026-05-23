class Solution {
public:
    void backtrack(int n, int open_remain, vector<string>& res, string s) {
        // reject early if not possible to cancel out
        if (n - s.length() < open_remain) {
            return;
        }

        if (s.length() == n) {
            if (open_remain == 0) { // NOTICE: add to res only when valid
                res.push_back(s);
            }
            return;
        }

        if (open_remain > 0) {
            // can add ) close paranthesis
            backtrack(n, open_remain - 1, res, s + ')');
        }
        backtrack(n, open_remain + 1, res, s + '(');

    }
    vector<string> generateParenthesis(int n) {
        // Key: At each position, we could append open ( or close )

        vector<string> res;

        backtrack(n * 2, 0, res, "");

        return res;
    }
};
