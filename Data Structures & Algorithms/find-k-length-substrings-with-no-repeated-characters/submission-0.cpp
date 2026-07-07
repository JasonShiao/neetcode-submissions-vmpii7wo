class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        // test cases:
        // k == 0 -> what would happen
        // s.length() == 0 or 1 -> what would happen

        unordered_set<char> window; // used char pool
        int l = 0;
        int res = 0;
        for (int r = 0; r < s.length(); r++) {
            
            // NOTICE: must also move l ptr to handle window size!!!!
            if (r - l + 1 > k) {
                window.erase(s[l]);
                l++;
            }

            if (window.find(s[r]) != window.end()) { // already exists
                while (l < r && window.find(s[r]) != window.end()) {
                    window.erase(s[l]);
                    l++;
                }
            }
            window.insert(s[r]);
            // check the new valid window
            if ((r - l + 1) == k) {
                res += 1;
            }
        }

        return res;
    }
};
