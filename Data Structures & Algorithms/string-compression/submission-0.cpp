class Solution {
public:
    int compress(vector<char>& chars) {
        // 1. whenever a new (diff) char encountered ->
        //   concludte the previous group, add one char
        //   and then move write ptr by one

        int r_ptr = 0;
        int w_ptr = 0;
        char cur_char = ' ';
        int cur_group_cnt = 0;
        while (r_ptr <= chars.size()) {
            if (r_ptr == chars.size()) {
                // conclude the last group
                if (cur_group_cnt > 1) {
                    vector<char> reverse_cnt_str;
                    while (cur_group_cnt > 0) {
                        reverse_cnt_str.push_back(cur_group_cnt % 10 + '0');
                        cur_group_cnt /= 10;
                    }
                    // reverse and add to result
                    for (auto rit = reverse_cnt_str.rbegin(); rit != reverse_cnt_str.rend(); rit++) {
                        chars[w_ptr] = *rit;
                        w_ptr++;
                    }
                }
                break;
            }

            if (chars[r_ptr] == cur_char) {
                // same group
                cur_group_cnt += 1;
            } else {
                // conclude the previous group and
                // add write the new char
                if (cur_group_cnt > 1) {
                    // write the prev cnt into result
                    vector<char> reverse_cnt_str;
                    while (cur_group_cnt > 0) {
                        reverse_cnt_str.push_back(cur_group_cnt % 10  + '0');
                        cur_group_cnt /= 10;
                    }
                    // reverse and add to result
                    for (auto rit = reverse_cnt_str.rbegin(); rit != reverse_cnt_str.rend(); rit++) {
                        chars[w_ptr] = *rit;
                        w_ptr++;
                    }
                }
                // No need to add the cnt string for prev group
                cur_char = chars[r_ptr];
                chars[w_ptr] = cur_char;
                w_ptr++;
                cur_group_cnt = 1;
            }
            r_ptr++;
        }

        return w_ptr;


    }
};