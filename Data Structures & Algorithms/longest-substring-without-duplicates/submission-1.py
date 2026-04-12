class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Whenever any duplicate char is encountered, finish the substring
        # check length, and start the new substring from the first non-duplicate of the first duplicate
        # e.g. abcdc123krf
        #        | |
        #   c duplicated
        #   remove c, start new from the 'd'
        left = 0
        right = 0
        lookup = {} # char: index
        max_len = 0
        temp_len = 0
        while right < len(s):
            if s[right] not in lookup:
                pass
                #print(f'add {s[right]} with index {right}')
            else:
                # cleanup and start the new substring
                max_len = max(temp_len, max_len)
                new_head = lookup[s[right]] + 1
                #print(f'New head {new_head}')
                while left < new_head:
                    #print(f'pop {s[left]} at {lookup[s[left]]}')
                    lookup.pop(s[left])
                    left += 1
                    temp_len -= 1

            lookup[s[right]] = right
            temp_len += 1
            right += 1
        
        max_len = max(temp_len, max_len)

        return max_len
