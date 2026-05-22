typedef std::pair<int, int> meeting;

struct Room {
    int id;
    //int used_cnt;
    int next_avail_time;
};

struct CompareId {
    bool operator()(const Room& a, const Room& b) {
        return a.id > b.id;
    }
};

struct CompareNextAvailTime {
    bool operator()(const Room& a, const Room& b) {
        // Tips: if we also order the id, we don't need to
        //       do while loop when moving from inuse to avail
        //       simply move one room could be enough
        if (a.next_avail_time == b.next_avail_time) {
            return a.id > b.id;
        }
        return a.next_avail_time > b.next_avail_time;
    }
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // min heap for meeting start
        // min heap for in-use room next avail time
        // min heap for unused room used time

        // priority_queue<meeting, vector<meeting>, greater<meeting>> meetings_heap;
        // priority_queue<Room, vector<Room>, CompareId> unused_rooms_heap;
        // priority_queue<Room, vector<Room>, CompareNextAvailTime> inuse_rooms_heap;

        // // add meetings to heap
        // for (auto m: meetings) {
        //     meetings_heap.push({m[0], m[1]});
        // }
        // // init all rooms in avail heap
        // for (int i = 0; i < n; i++) {
        //     Room r;
        //     r.id = i;
        //     r.used_cnt = 0;
        //     r.next_avail_time = 0;
        //     unused_rooms_heap.push(r);
        // }

        // int current_time = 0;
        // int max_used_cnt = 0;
        // int max_used_id = -1;
        // while (!meetings_heap.empty()) {
        //     if (meetings_heap.top().first <= current_time) {
        //         // whether any room available
        //         if (unused_rooms_heap.empty()) {
        //             // not available -> fast forward to the next avail time
        //             current_time = inuse_rooms_heap.top().next_avail_time;
        //             while (!inuse_rooms_heap.empty() &&
        //                     inuse_rooms_heap.top().next_avail_time <= current_time) {
        //                 unused_rooms_heap.push(inuse_rooms_heap.top());
        //                 inuse_rooms_heap.pop();
        //             }
        //         } else {
        //             // available -> use the top
        //             auto m = meetings_heap.top();
        //             meetings_heap.pop();
        //             auto r = unused_rooms_heap.top();
        //             unused_rooms_heap.pop();
        //             r.next_avail_time = current_time + m.second - m.first;
        //             r.used_cnt += 1;
        //             if (r.used_cnt > max_used_cnt) {
        //                 max_used_cnt = r.used_cnt;
        //                 max_used_id = r.id;
        //             }
        //             inuse_rooms_heap.push(r);
        //         }
        //     } else {
        //         // need to fast forward to start of the next meeting
        //         current_time = meetings_heap.top().first;
        //         // update meeting rooms status
        //         while (!inuse_rooms_heap.empty() &&
        //                 inuse_rooms_heap.top().next_avail_time <= current_time) {
        //             unused_rooms_heap.push(inuse_rooms_heap.top());
        //             inuse_rooms_heap.pop();
        //         }
        //     }

        // }

        // return max_used_id;

        priority_queue<meeting, vector<meeting>, greater<meeting>> meetings_heap;
        priority_queue<Room, vector<Room>, CompareId> unused_rooms_heap;
        priority_queue<Room, vector<Room>, CompareNextAvailTime> inuse_rooms_heap;

        vector<int> used_cnt(n, 0);

        for (auto& m : meetings) {
            meetings_heap.push({m[0], m[1]});
        }

        for (int i = 0; i < n; i++) {
            unused_rooms_heap.push({i, 0});
        }

        long long current_time = 0;

        while (!meetings_heap.empty()) {
            auto m = meetings_heap.top();
            meetings_heap.pop();

            // fast forward to start of meeting
            if (m.first > current_time) {
                current_time = m.first;
            }
            // update rooms status (whenever current time changes)
            while (!inuse_rooms_heap.empty() &&
                   inuse_rooms_heap.top().next_avail_time <= current_time) {
                unused_rooms_heap.push(inuse_rooms_heap.top());
                inuse_rooms_heap.pop();
            }

            // fast forward for room if no room available
            if (unused_rooms_heap.empty()) {
                current_time = inuse_rooms_heap.top().next_avail_time;
                // update rooms status (whenever current time changes)
                while (!inuse_rooms_heap.empty() &&
                       inuse_rooms_heap.top().next_avail_time <= current_time) {
                    unused_rooms_heap.push(inuse_rooms_heap.top());
                    inuse_rooms_heap.pop();
                }
                // NOTE: actually we don't need to while loop here
                //       move single top is enough, but it is fine to move all avail
            }

            // assign the meeting to the room
            Room r = unused_rooms_heap.top();
            unused_rooms_heap.pop();

            long long duration = m.second - m.first;
            r.next_avail_time = current_time + duration;

            used_cnt[r.id]++;

            inuse_rooms_heap.push(r);
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (used_cnt[i] > used_cnt[ans]) {
                ans = i;
            }
        }

        return ans;

    }
};