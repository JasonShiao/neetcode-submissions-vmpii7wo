class Solution {
public:
    string longestPalindrome(int l, int r, string s) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l-= 1;
            r+= 1;
        }

        // be careful about the index
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s) {
        // Target Time complexity: O(n^2) < brute force O(n^3)
        string longest = "";
        for (int i = 0; i < s.length(); i++) {
            auto odd = longestPalindrome(i, i, s);
            auto even = longestPalindrome(i, i+1, s);
            if (odd.length() > longest.length()) {
                longest = odd;
            }
            if (even.length() > longest.length()) {
                longest = even;
            }
        }

        return longest;
    }
};
