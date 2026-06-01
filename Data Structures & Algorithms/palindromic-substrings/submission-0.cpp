class Solution {
public:
    int countPalindrome(int l, int r, string s) {
        int cnt = 0;
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            cnt += 1;
            l--;
            r++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        // brute force: O(n^3) 
        //      = O(n^2) num of substring * O(n) check for each substring
        // Partial sets of substrings of a palindrome are also palindromes
        int cnt = 0;
        // simple trick to avoid counting the repeat palindrome candidate substring
        // select a center -> expand gradually
        for (int i = 0; i < s.length(); i++) {
            // odd
            cnt += countPalindrome(i, i, s);
            // even
            cnt += countPalindrome(i, i+1, s);
        }
        return cnt;
    }
};
