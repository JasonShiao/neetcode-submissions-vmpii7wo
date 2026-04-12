class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> char_cnt(26,0);
        for (int i = 0; i < s1.length(); i++) {
            char_cnt[s1[i] - 'a'] += 1;
        }
        int left = 0;
        for (int right = 0; right < s2.length(); right++) {
            if (right < s1.length()) {
                // only accumulate
                char_cnt[s2[right] - 'a'] -= 1;
            } else {
                char_cnt[s2[right] - 'a'] -= 1;
                char_cnt[s2[left] - 'a'] += 1;
                left += 1;
            }
            // check all 0: i.e. all char cnt match
            bool all_zero = true;
            for (int x : char_cnt) {
                if (x != 0) {
                    all_zero = false;
                    break;
                }
            }
            if (all_zero) {
                return true;
            }

        }
        return false;


    }
};
