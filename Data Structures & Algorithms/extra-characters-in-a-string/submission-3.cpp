class TrieNode {
public:
    TrieNode () {}
    unordered_map<char, TrieNode*> child;
    bool word = false;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie (vector<string>& dictionary) {
        root = new TrieNode;
        for (auto word: dictionary) {
            TrieNode* cur = root;
            for (auto c: word) {
                if (cur->child.find(c) == cur->child.end()) {
                    // create the branch (node)
                    cur->child[c] = new TrieNode;
                }
                cur = cur->child[c];
            }
            cur->word = true;
        }
    }

    bool find(const string& word) {
        TrieNode* cur = root;
        for (auto c: word) {
            if (cur->child.find(c) == cur->child.end()) {
                return false;
            }
            cur = cur->child[c];
        }
        
        return cur->word;
    }
};

class Solution {
public:
    int dfs_dp(int idx, const string& s, vector<string>& dictionary,
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
        int min_extra = 1 + dfs_dp(idx+1, s, dictionary, dp_table);
        // case 2: include idx (idx being the start of a word)
        for (int j = idx; j < s.length(); j++) {
            string sub_s = s.substr(idx, j-idx+1);
            // here is where we could optimize with a trie
            // instead of looping through all words every time
            for (auto word: dictionary) {
                if (sub_s == word) {
                    min_extra = min(min_extra, dfs_dp(j+1, s, dictionary, dp_table));
                }
            }
            // --------------------
        }
        dp_table[idx] = min_extra;

        return min_extra;
    }

    int dfs_trie(int idx, const string& s, Trie& dict_trie, unordered_map<int, int>& dp_table) {
        if (dp_table.find(idx) != dp_table.end()) {
            return dp_table[idx];
        }
        
        if (idx >= s.length()) {
            return 0;
        }

        int min_extra = 1 + dfs_trie(idx + 1, s, dict_trie, dp_table);
        for (int j = idx; j < s.length(); j++) {
            string substr = s.substr(idx, j-idx+1);
            if (dict_trie.find(substr)) {
                min_extra = min(min_extra, dfs_trie(j+1, s, dict_trie, dp_table));
            }
        }

        dp_table[idx] = min_extra;
        return min_extra;

    }

    int minExtraChar(string s, vector<string>& dictionary) {
        // Approach 1: DP
        unordered_map<int, int> dp_table;
        // return dfs_dp(0, s, dictionary, dp_table);

        // Approach 2: DP + Trie
        // 1. build a trie from dictionary
        Trie trie(dictionary);
        // DFS with trie dict
        return dfs_trie(0, s, trie, dp_table);

    }
};