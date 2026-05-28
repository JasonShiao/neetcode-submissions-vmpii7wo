class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        // reject mismatch of sentence length
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        
        // By description: For each pair of words, need to lookup similarPairs
        
        // -> create a hash map -> mapping words to its similar words (may be multiple)
        unordered_map<string, unordered_set<string>> simi_lookup;
        for (auto simi_pair: similarPairs) {
            // bidirectional (add both)
            simi_lookup[simi_pair[0]].insert(simi_pair[1]);
            simi_lookup[simi_pair[1]].insert(simi_pair[0]);
        }

        for (int i = 0; i < sentence1.size(); i++) {
            // exactly match
            if (sentence1[i] == sentence2[i]) {
                continue;
            }
            if (simi_lookup[sentence1[i]].find(sentence2[i]) == simi_lookup[sentence1[i]].end()) {
                // not similar
                return false;
            }
        }

        return true;

    }
};
