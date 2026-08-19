class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // store the first appearance and last appearance of a char
        vector<int> first_appear(26, -1);
        vector<int> last_appear(26, -1);

        for (int i = 0; i < s.length(); i++) {
            if (first_appear[s[i] - 'a'] == -1) {
                first_appear[s[i] - 'a'] = i;
            } else {
                // appear before, update the last appear
                last_appear[s[i] - 'a'] = i;
            }
        }

        int max_length = -1;
        for (int i = 0; i < 26; i++) {
            if (first_appear[i] != -1 && last_appear[i] != -1) {
                max_length = max(max_length, last_appear[i] - first_appear[i] - 1);
            }
        }

        return max_length;
    }
};