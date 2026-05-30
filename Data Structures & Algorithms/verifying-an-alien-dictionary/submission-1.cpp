class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        bool res = true;

        // create a char order map
        unordered_map<char, int> char_order;
        for (int i = 0; i < order.length(); i++) {
            char_order[order[i]] = i;
        }

        // for each pair, check the order
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            for (int cur = 0; cur < w1.length(); cur++) {
                if (cur == w2.length()) {
                    // second word is shorter -> incorrect order
                    return false;
                } else if (char_order[w1[cur]] > 
                    char_order[w2[cur]]) {
                    return false;
                } else if (char_order[w1[cur]] < 
                    char_order[w2[cur]]) {
                    // confirmed correct order
                    break;
                } // else ==, undetermined -> compare next char
            }
        }

        return res;
    }
};