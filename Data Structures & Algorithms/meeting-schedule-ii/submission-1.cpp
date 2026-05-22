/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Pivot {
public:
    Pivot (int time, int inc_dec) {
        this->time = time;
        this->inc_dec = inc_dec;
    }
    int time;
    int inc_dec;
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // Method 1: My intuitive approach (but require extra O(n) space!)
        // vector<Pivot> pivots;
        // for (auto intvl: intervals) {
        //     pivots.push_back({intvl.start, 1});
        //     pivots.push_back({intvl.end, -1});
        // }

        // sort(pivots.begin(), pivots.end(), 
        //     [](const Pivot& a, const Pivot& b) {
        //         return a.time < b.time;
        //     });
        
        int overlapped = 0;
        int max_overlapped = 0;
        // int cur_time = 0;
        // for (int i = 0; i < pivots.size(); i++) {
        //     if (pivots[i].time == cur_time) {
        //         overlapped += pivots[i].inc_dec; 
        //         // not concluded for the time yet 
        //         // -> don't max update overlap now
        //     } else {
        //         // conclude the last
        //         if (overlapped > max_overlapped) {
        //             max_overlapped = overlapped;
        //         }
        //         cur_time = pivots[i].time;
        //         overlapped += pivots[i].inc_dec;
        //     }
        // }

        // return max_overlapped;

        // Method 2:
        // similar, but sort starts and ends separately
        vector<int> starts;
        vector<int> ends;
        for (auto intvl: intervals) {
            starts.push_back(intvl.start);
            ends.push_back(intvl.end);
        }
        // sort
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int i_start = 0;
        int i_end = 0;
        while (i_start < starts.size()) {
            if (starts[i_start] == ends[i_end]) {
                // tie -> increment both
                i_start += 1;
                i_end += 1;
            } else if (starts[i_start] < ends[i_end]) {
                overlapped += 1;
                if (overlapped > max_overlapped) {
                    max_overlapped = overlapped;
                }
                i_start += 1;
            } else {
                overlapped -= 1;
                i_end += 1;
            }
        }

        return max_overlapped;
    }
};
