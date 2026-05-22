class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return 0;
        }

        // sort by start first
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
        });

        // Greedy iterate and remove when overlaps, 
        // Critical: How to handle "regret"? (simply remove the first is not optimal)
        // Tips: 
        //   For special case where one interval contains the other 
        //   -> remove the longer one is optimal strategy
        int last_start = intervals[0][0];
        int last_end = intervals[0][1];
        int remove_cnt = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last_end) {
                // overlapped
                if (intervals[i][0] == last_start) { // start at the same time
                    last_end = min(last_end, intervals[i][1]);
                } else { // not start at the same time
                    if (intervals[i][1] <= last_end) { // contain
                        last_start = intervals[i][0];
                        last_end = intervals[i][1];
                    } else { // simple overlap (non contain)
                        // remove the latter one
                        // i.e. preserve last_start, last_end
                    }
                }
                // For either case, will remove exact one interval
                remove_cnt += 1;
            } else {
                // non-overlapping
                last_start = intervals[i][0];
                last_end = intervals[i][1];
            }
        }
        
        return remove_cnt;
    }
};
