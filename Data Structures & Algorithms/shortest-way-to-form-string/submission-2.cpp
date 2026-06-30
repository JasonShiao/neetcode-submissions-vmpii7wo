class Solution {
public:
    int shortestWay(string source, string target) {
        // Intuition:
        // For subsequence problem, always select the first match char (no regret needed)
        // because for the same matched char after the first one, the result remains the same or worse

        // Approach 2: 
        //   create a 2D lookup [S][26] for source
        //   indicating the first idx of char after (inclusive) each pos of source
        //   Time: O(S+T)
        //   Memory: O(S)
        vector<vector<int>> source_lookup(source.length(), 
                vector<int>(26, -1)); // dimension: [S][26]
        // build from end to front: O(26*S)
        vector<int> tmp_lookup(26, -1); // -1 indicates no such char
        for (int i = source.length() - 1; i >= 0; i--) {
            tmp_lookup[source[i] - 'a'] = i;
            source_lookup[i] = tmp_lookup;
        }
        // start iterate through target
        int s_cur = 0;
        int t_cur = 0;
        int res = 0;
        while (t_cur < target.length()) {
            if (s_cur == 0) { // whenever start from 0 -> a new subseq created
                res += 1;
            }
            if (source_lookup[s_cur][target[t_cur] - 'a'] >= 0) {
                s_cur = source_lookup[s_cur][target[t_cur] - 'a'] + 1;
                s_cur %= source.length(); // handle exceeding
                t_cur += 1;
            } else {
                // try from start of source
                if (source_lookup[0][target[t_cur] - 'a'] >= 0) {
                    s_cur = 0; // for next loop                    
                } else {
                    return -1; // not possible even start from init of source
                }
            }
        }

        return res;

        // Approach 1: 
        //   two pointers, one for s, one for target
        //   Almost brute force: O(S*T)
        // int res = 0;
        // int cur1 = 0;
        // int cur2 = 0;
        // int last_cur2 = 0;
        // while (cur2 < target.length()) {
        //     if (source[cur1] == target[cur2]) {
        //         cur1 += 1;
        //         cur2 += 1;
        //         if (cur1 == source.length()) {
        //             cur1 = 0;
        //             res += 1;
        //         }
        //     } else {
        //         // move cur1 only
        //         cur1 += 1;
        //         if (cur1 == source.length()) {
        //             if (last_cur2 == cur2) {
        //                 // already test all and no match
        //                 return -1;
        //             }
        //             cur1 = 0;
        //             res += 1;
        //             last_cur2 = cur2;
        //         }
        //     }
        // }

        // if (cur1 != 0) {
        //     res += 1;
        // }

        return res;
    }
};
