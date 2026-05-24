class Solution {
public:
    int characterReplacement(string s, int k) {
        // Key: window_size - count_of_most_frequent_char_in_window <= k
        
        // window size - freq(max freq char) <= k
        // i.e. there can be at most (k) char in the window 
        //      distinct from the max freq char

        vector<int> window_char_freq(26, 0); // 26 alphabets

        int l = 0;
        int longest_repeat = 0;
        int max_freq = 0;
        //int cur_len = 0;
        for (int r = 0; r < s.length(); r++) {
            // Extend: include s[r] into the window
            window_char_freq[s[r] - 'A'] += 1;
            //cur_len += 1;

            // handle max_freq
            // only need to check the cnt of "the latest" included char
            max_freq = max(max_freq, window_char_freq[s[r] - 'A']);
            // when invalid, shrink until valid
            while ((r - l + 1) > max_freq + k) {
                // move l and check again
                window_char_freq[s[l] - 'A'] -= 1;
                //max_freq = max(max_freq, window_char_freq[s[l] - 'A'] - 1);
                l++;
            }
            
            longest_repeat = max(longest_repeat, r - l + 1);
        }

        return longest_repeat;
    }
};
