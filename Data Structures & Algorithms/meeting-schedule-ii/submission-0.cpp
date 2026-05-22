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
        // My intuitive approach (but require extra O(n) space!)
        vector<Pivot> pivots;
        for (auto intvl: intervals) {
            pivots.push_back({intvl.start, 1});
            pivots.push_back({intvl.end, -1});
        }

        sort(pivots.begin(), pivots.end(), 
            [](const Pivot& a, const Pivot& b) {
                return a.time < b.time;
            });
        
        int overlapped = 0;
        int max_overlapped = 0;
        int cur_time = 0;
        for (int i = 0; i < pivots.size(); i++) {
            if (pivots[i].time == cur_time) {
                overlapped += pivots[i].inc_dec; 
                // not concluded for the time yet 
                // -> don't max update overlap now
            } else {
                // conclude the last
                if (overlapped > max_overlapped) {
                    max_overlapped = overlapped;
                }
                cur_time = pivots[i].time;
                overlapped += pivots[i].inc_dec;
            }
        }

        return max_overlapped;

        // 1. First, Sort intervals with start 
        // sort(intervals.begin(), intervals.end(),
        //     [](const Interval& a, const Interval& b) {
        //         return a.start < b.start;
        //     }
        // );

        // int overlap_layer_cnt = 0;
        // int max_overlap_layer_cnt = 0;
        // // 2. Iterate, when encounter start -> +1, end -> -1
        // for (int i = 0; i < intervals.size(); i++) {

        // }

        
       //return max_overlap_layer_cnt;
    }
};
