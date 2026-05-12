class Solution {
public:
    bool dividePalindrome(string& s, int l, int r, bool can_delete) {
        while (l < r) {
            if (s[l] == s[r]) {
                l += 1;
                r -= 1;
            } else {
                // not equal, try to delete from either side
                if (!can_delete) {
                    return false;
                }
                if (dividePalindrome(s, l+1, r, false)) {
                    return true;
                } else if (dividePalindrome(s, l, r-1, false)) {
                    return true;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
    bool validPalindrome(string s) {
        return dividePalindrome(s, 0, s.length()-1, true);
    }
};