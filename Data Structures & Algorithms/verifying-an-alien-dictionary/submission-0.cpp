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
            int cur = 0;
            while (cur < words[i].length() && 
                    cur <= words[i+1].length()) {
                if (cur == words[i+1].length()) {
                    // second word is shorter -> incorrect order
                    res = false;
                    break;
                } else if (char_order[words[i][cur]] > 
                    char_order[words[i+1][cur]]) {
                    // confirmed incorrect order
                    res = false;
                    break;
                } else if (char_order[words[i][cur]] < 
                    char_order[words[i+1][cur]]) {
                    // confirmed correct order
                    break;
                } // else ==, compare next char
                cur += 1;
            }

            if (!res) {
                break;
            }
        }

        return res;
    }
};