class Solution {
public:
    int shortestWay(string source, string target) {
        // Intuition:
        // For subsequence problem, always select the first match char (no regret needed)
        // because for the same matched char after the first one, the result remains the same or worse

        // Almost brute force: O(mn)
        // two pointers: one for s, one for target
        int res = 0;
        int cur1 = 0;
        int cur2 = 0;
        int last_cur2 = 0;
        while (cur2 < target.length()) {
            if (source[cur1] == target[cur2]) {
                cur1 += 1;
                cur2 += 1;
                if (cur1 == source.length()) {
                    cur1 = 0;
                    res += 1;
                }
            } else {
                // move cur1 only
                cur1 += 1;
                if (cur1 == source.length()) {
                    if (last_cur2 == cur2) {
                        // already test all and no match
                        return -1;
                    }
                    cur1 = 0;
                    res += 1;
                    last_cur2 = cur2;
                }
            }
        }

        if (cur1 != 0) {
            res += 1;
        }

        return res;
    }
};
