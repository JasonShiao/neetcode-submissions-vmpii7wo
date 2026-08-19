class Solution {
public:
    int maxScore(string s) {
        // O(n) for naive brute force

        int num_zero_l = 0;
        int num_one_r = 0;
        for (auto c: s) {
            if (c == '1') {
                num_one_r += 1;
            }
        }

        // ensure non-empty
        if (s[0] == '0') {
            num_zero_l += 1;
        } else {
            num_one_r -= 1;
        }

        int cursor = 1;
        int max_score = num_zero_l + num_one_r;
        while (cursor < s.length() - 1) {
            if (s[cursor] == '1') {
                // dec num_one_r
                num_one_r -= 1;
            } else {
                // inc num_zero_l
                num_zero_l += 1;
                max_score = max(num_one_r + num_zero_l, max_score);
            }

            cursor++;
        }

        return max_score;
    }
};