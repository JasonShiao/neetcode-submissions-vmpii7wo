class Solution {
private:
    vector<vector<char>> char_map = {
        {'+'},
        {},
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'},
        {'j', 'k', 'l'},
        {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'},
        {'t', 'u', 'v'},
        {'w', 'x', 'y', 'z'}
    };
public:
    void backtrack(const string& digits, int i, 
            vector<string>& res, string cur_s) {
        if (i >= digits.length()) {
            res.push_back(cur_s); // no extra condition to reject answer
            return;
        }

        auto char_list = char_map[digits[i] - '0'];
        for (int x = 0; x < char_list.size(); x++) {
            backtrack(digits, i + 1, res, cur_s + char_list[x]);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;

        // margin case: empty
        if (digits.empty()) {
            return res;
        }

        backtrack(digits, 0, res, "");

        return res;
    }
};
