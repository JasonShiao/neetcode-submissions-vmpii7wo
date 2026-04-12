class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagram_cnt_list = []
        anagram_groups = []
        for s in strs:
            anagram_cnt = [0] * 26
            for c in s:
                anagram_cnt[ord(c) - ord('a')] += 1
            matched = False
            for i, cnt in enumerate(anagram_cnt_list):
                if cnt == anagram_cnt:
                    anagram_groups[i].append(s)
                    matched = True
                    break
            if not matched:
                anagram_cnt_list.append(anagram_cnt)
                anagram_groups.append([s])
        
        return anagram_groups


