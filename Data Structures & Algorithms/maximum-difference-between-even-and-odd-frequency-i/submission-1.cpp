class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> char_freq;
        for (auto c: s) {
            char_freq[c] += 1;
        }
        int max_odd = 0;
        int min_even = INT_MAX;
        for (auto [k_ch, cnt]: char_freq) {
            if (cnt % 2) {
                max_odd = max(max_odd, cnt);
            } else {
                min_even = min(min_even, cnt);
            }
        }

        return max_odd - min_even;
    }
};