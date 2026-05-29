class Solution {
public:
    int dfs(int idx, const string& s, vector<string>& dictionary,
        unordered_map<int, int>& dp_table) {
        // Meaning of idx: min extra char to start from idx of s

        // Key part of a DP: table lookup and avoid repeating
        if (dp_table.find(idx) != dp_table.end()) {
            return dp_table[idx];
        }

        if (idx >= s.length()) {
            return 0;
        }

        // each "start of substring" can be the start of word or skipped
        // case 1: skip idx (+1 for skipping this idx)
        int min_extra = 1 + dfs(idx+1, s, dictionary, dp_table);
        // case 2: include idx (idx being the start of a word)
        for (int j = idx; j < s.length(); j++) {
            string sub_s = s.substr(idx, j-idx+1);
            for (auto word: dictionary) {
                if (sub_s == word) {
                    min_extra = min(min_extra, dfs(j+1, s, dictionary, dp_table));
                }
            }
        }
        dp_table[idx] = min_extra;

        return min_extra;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        // Approach 1: DP
        unordered_map<int, int> dp_table;
        return dfs(0, s, dictionary, dp_table);

        // 1. build a trie from dictionary

    }
};