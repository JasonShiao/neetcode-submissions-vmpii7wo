class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Key requirement: No extra memory used (just O(1) in memory)
        #    -> can't reverse the string (extra memory)
        #    -> can't strip ignored char to get a new string
        # use two pointers
        i = 0
        j = len(s)-1
        while i < j:
            while (not s[i].isalnum()) and i < j:
                i += 1
            while (not s[j].isalnum()) and i < j:
                j -= 1
            if s[i].lower() != s[j].lower():
                return False

            i += 1
            j -= 1
        
        return True