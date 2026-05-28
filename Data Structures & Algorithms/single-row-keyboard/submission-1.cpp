class Solution {
public:
    int calculateTime(string keyboard, string word) {
        // build a map from char to idx
        unordered_map<char, int> char_idx_map;
        for (int i = 0; i < keyboard.length(); i++) {
            char_idx_map[keyboard[i]] = i;
        }

        // sum the dist within each pair of neighbor char
        int last_idx = 0;
        int time = 0;
        for (auto c: word) {
            // NOTICE: not abs dist for char!!
            int curr_idx = char_idx_map[c];
            time += abs(curr_idx - last_idx);
            last_idx = curr_idx;
        }

        return time;
    }
};
