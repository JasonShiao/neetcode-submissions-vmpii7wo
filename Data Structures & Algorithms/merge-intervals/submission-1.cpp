class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }

        // 1. sort by start first
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
        });

        // 2. iterate 
        vector<vector<int>> res;
        int cur_start = intervals[0][0];
        int cur_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= cur_end) {
                // NOTE: cur_start will not change since intervals have been sorted by start
                // merge
                cur_end = max(cur_end, intervals[i][1]);
            } else {
                // non-overlapping, conclude and add the prev interval to res
                res.push_back({cur_start, cur_end});
                cur_start = intervals[i][0];
                cur_end = intervals[i][1];
            }
        }

        // add the last interval
        res.push_back({cur_start, cur_end});

        return res;
    }
};
