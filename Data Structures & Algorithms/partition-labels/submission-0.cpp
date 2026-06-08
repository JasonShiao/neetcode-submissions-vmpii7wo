class Solution {
public:
    vector<int> partitionLabels(string s) {
        // create interval for each letter
        // merge any overlap intervals
        vector<int> first(26, -1), last(26, -1);

        // O(n)
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) {
                first[c] = i;
            }
            last[c] = i;
        }

        // considered O(1)
        vector<pair<int, int>> intervals;
        for (int c = 0; c < 26; c++) {
            if (first[c] != -1) {
                intervals.push_back({first[c], last[c]});
            }
        }

        // Considered O(1)
        sort(intervals.begin(), intervals.end());

        vector<int> res;
        // start and end for current interval
        int start = intervals[0].first;
        int end = intervals[0].second;

        // O(1)
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first <= end) {
                end = max(end, intervals[i].second);
            } else {
                res.push_back(end - start + 1);
                start = intervals[i].first;
                end = intervals[i].second;
            }
        }

        res.push_back(end - start + 1);
        return res;
    }
};
