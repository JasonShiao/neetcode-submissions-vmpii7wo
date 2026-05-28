class Solution {
public:
    bool canPermutePalindrome(string s) {
        // Cf. check whether a string is palindrome is simple using two pointers
        
        // check any permutation -> only need to count the chars
        // at most one char can occur odd # of times
        
        // trick: use a set to insert and erase 
        // -> char those occur even number of time will be cancelled out
        unordered_set<char> ch_set;
        for (auto c: s) {
            if (ch_set.find(c) == ch_set.end()) {
                ch_set.insert(c);
            } else {
                ch_set.erase(c);
            }
        }
        if (ch_set.size() > 1) {
            return false;
        } else {
            return true;
        }
    
    }
};
