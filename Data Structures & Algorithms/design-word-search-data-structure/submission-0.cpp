class TrieNode {
public:
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
    bool word_marker = false;
    TrieNode* child[26];
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for (auto c: word) {
            if (cur->child[c - 'a'] == nullptr) {
                // node not create yet
                cur->child[c - 'a'] = new TrieNode;
            }
            cur = cur->child[c - 'a'];
        }
        cur->word_marker = true;
    }
    
    bool backtracking(const string& word, int idx, TrieNode* cur) {
        // word[idx] to be checked with cur->child[..]
        if (idx >= word.length()) {
            return true;
        }

        // check terminate (check word marker)
        char cur_char = word[idx];
        if (idx + 1 == word.length()) {
            bool res = false;
            if (cur_char == '.') {
                for (int i = 0; i < 26; i++) {
                    if (cur->child[i] == nullptr) continue;
                    if (cur->child[i]->word_marker) {
                        res = true;
                        break;
                    }
                }
            } else {
                if (cur->child[cur_char - 'a'] != nullptr && 
                    cur->child[cur_char - 'a']->word_marker) {
                    res = true;
                }
            }
            return res;
        }

        if (cur_char == '.') {
            // handle wild card -> search all branches
            bool res = false;
            for (int i = 0; i < 26; i++) {
                if (cur->child[i] != nullptr) {
                    res |= backtracking(word, idx+1, cur->child[i]);
                }
            }
            return res;
        } else {
            // single branch
            if (cur->child[cur_char - 'a'] == nullptr) {
                return false;
            }
            return backtracking(word, idx+1, cur->child[cur_char - 'a']);
        }

    }

    bool search(string word) {
        // Need backtrack mechanism to handle wiildcard!!
        TrieNode* cur = root;

        return backtracking(word, 0, cur);
    }
};
