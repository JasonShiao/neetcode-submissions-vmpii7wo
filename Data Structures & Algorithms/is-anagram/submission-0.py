class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        char_cnt = [0]*26
        if len(s) != len(t):
            return False

        for i in range(len(s)):
            char_cnt[ord(s[i]) - ord('a')] += 1
            char_cnt[ord(t[i]) - ord('a')] -= 1
        
        if all([cnt == 0 for cnt in char_cnt]):
            return True
        
        return False

