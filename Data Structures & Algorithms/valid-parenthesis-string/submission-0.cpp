class Solution {
public:
    bool checkValidString(string s) {
        // !!!still haven't fully understand yet!!!!

        int left_min = 0;
        int left_max = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                left_min += 1;
                left_max += 1;
            } else if (s[i] == ')') {
                left_min -= 1;
                left_max -= 1;
            } else {
                left_min -= 1;
                left_max += 1;
            }
            if (left_max < 0) {
                return false;
            }

            left_min = max(0, left_min);
        }

        return left_min == 0;
    }
};
