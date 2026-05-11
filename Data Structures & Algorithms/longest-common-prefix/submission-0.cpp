class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common_prefix = "";
        bool match = true;
        for (auto i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for (auto j = 1; j < strs.size(); j++) {
                if (c != strs[j][i]) {
                    match = false;
                }
            }
            if (match) {
                common_prefix.push_back(c);
            } else {
                break;
            }
        }
        return common_prefix;
    }
};