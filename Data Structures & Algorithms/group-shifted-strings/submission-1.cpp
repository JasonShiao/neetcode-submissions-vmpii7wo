class TrieNode {
public:
    TrieNode() {}
    unordered_map<int, TrieNode*> child; // key: relative char val
    int group_idx = -1;
};

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        // "relative" char vals determine whether they are in the same 
        // shifting sequence

        // Alternative approach: use hashing with a string of relative char
        //                       shift all key strings to start from 'a'

        // Build a trie for search group idx
        // i.e. the node in the trie point to the index of group
        // if no group exist -> create one
        vector<vector<string>> res;

        TrieNode* root = new TrieNode;
        for (auto str: strings) {
            TrieNode* cur = root;
            for (int i = 0; i < (str.length() - 1); i++) {
                // NOTICE: must handle wrap-around 
                int relative_char_val = str[i+1] - str[i];
                if (relative_char_val < 0) {
                    // (convert negative to positive)
                    relative_char_val += 26;
                }

                if (cur->child.find(relative_char_val) == cur->child.end()) {
                    cur->child[relative_char_val] = new TrieNode;
                }
                cur = cur->child[relative_char_val];
            }
            
            if (cur->group_idx == -1) {
                // if no existing group match this str yet
                // create a new group
                res.push_back({str});
                cur->group_idx = res.size() - 1;
            } else {
                // add to the group
                res[cur->group_idx].push_back(str);
            }
        }



        return res;
    }
};
