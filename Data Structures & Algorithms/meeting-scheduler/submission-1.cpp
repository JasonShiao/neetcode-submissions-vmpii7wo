class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        // 1. sort time slot (if not sorted)
        sort(slots1.begin(), slots1.end(), [](vector<int>& a, vector<int>& b) {
            return a < b;
        });
        sort(slots2.begin(), slots2.end(), [](vector<int>& a, vector<int>& b) {
            return a < b;
        });

        // search for overlap slots
        // if overlap >= duration -> return res

        // Two overlap cases:
        //  1. start2 <= end1 <= end2
        //  2. start1 <= end2 <= end1
        // overlapped = [max(start1, start2), min(end1, end2)]
        vector<int> res; // empty interval
        int cur1 = 0;
        int cur2 = 0;
        while (cur1 < slots1.size() && cur2 < slots2.size()) {
            if ((slots1[cur1][1] <= slots2[cur2][1] && 
                slots1[cur1][1] >= slots2[cur2][0]) || 
                (slots2[cur2][1] <= slots1[cur1][1] && 
                slots2[cur2][1] >= slots1[cur1][0])) {
                int overlap_start = max(slots1[cur1][0], slots2[cur2][0]);
                int overlap_end = min(slots1[cur1][1], slots2[cur2][1]);
                int overlap = overlap_end - overlap_start;
                if (overlap >= duration) {
                    res.push_back(overlap_start);
                    res.push_back(overlap_start + duration); // NOTICE: this is not overlap end
                    break;
                }
            }
            // skip the one that ends earlier
            if (slots1[cur1][1] < slots2[cur2][1]) {
                cur1 += 1;
            } else {
                cur2 += 1;
            }
        }

        return res;
    }
};
