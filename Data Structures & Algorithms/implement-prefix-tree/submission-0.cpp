class TrieNode {
public:
    TrieNode() {}
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class PrefixTree {
private:
    TrieNode* root = nullptr;
public:
    PrefixTree() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* cur_node = root;

        for (auto c: word) {
            if (cur_node->children.find(c) == cur_node->children.end()) {
                // insert a new child
                auto new_node = new TrieNode;
                cur_node->children[c] = new_node; 
            }
            // move cursor
            cur_node = cur_node->children[c];
        }
        // mark a word for cur_node
        cur_node->word = true;
    }
    
    bool search(string word) {
        TrieNode* cur_node = root;

        for (auto c: word) {
            if (cur_node->children.find(c) == cur_node->children.end()) {
                return false;
            }
            cur_node = cur_node->children[c];
        }
        // check if this node is marked as a word
        return cur_node->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur_node = root;

        for (auto c: prefix) {
            if (cur_node->children.find(c) == cur_node->children.end()) {
                return false;
            }
            cur_node = cur_node->children[c];
        }
        return true;
    }
};
