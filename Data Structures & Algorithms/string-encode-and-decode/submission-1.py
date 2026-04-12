class Solution:

    def encode(self, strs: List[str]) -> str:
        strlen_list = []
        for s in strs:
            strlen_list.append(str(len(s)))
        result = str(len(strs)) + "$"
        if len(strs) > 0:
            result += "#".join(strlen_list)
            result += "#"
            result2 = ''.join(strs)
            result += result2

        # str_num$len1#len2#len3#...#strs
        return result

    def decode(self, s: str) -> List[str]:
        cur = 0
        num_str = 0
        num_str_list = []
        while True:
            if s[cur] == "$":
                num_str = int(''.join(num_str_list))
                cur += 1
                break
            num_str_list.append(s[cur])
            cur += 1
            if cur == len(s):
                raise Exception('no anchor found')
        
        # get length of each str
        str_len_list = []
        str_len_char_list = []
        sharp_cnt = 0
        while cur < len(s):
            if s[cur] == "#":
                str_len_list.append(int(''.join(str_len_char_list)))
                sharp_cnt += 1
                str_len_char_list = []
                # check sharp cnt
                if sharp_cnt >= num_str:
                    cur += 1
                    break
            else:
                str_len_char_list.append(s[cur])

            cur += 1
        
        # build each str
        str_list = []
        for s_len in str_len_list:
            str_list.append(s[cur:cur+s_len])
            cur += s_len
        
        return str_list
            
