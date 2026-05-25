// struct Task {
//     int next_cooldown_time;
//     char id;

//     // A min-heap requires 'greater than' comparison to keep the smallest at the top
//     bool operator>(const Task& other) const {
//         return next_cooldown_time > other.next_cooldown_time;
//     }
// };

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // node store: next timestamp after cooldown, num of remaining for char
        unordered_map<char, int> remained;
        priority_queue<int> max_freq_heap; // frequencies

        for (auto& t: tasks) {
            remained[t] += 1;
        }

        for (const auto& [key, value] : remained) {
            max_freq_heap.push(value);
        }

        // This doesn't work, the order matters if all tasks have been cooled down
        // e.g.
        // A B C | A | | | A
        // B C A | | | A | | | A -> will not be least cycle
        int current_time = 0;
        // while (!min_heap.empty()) {
        //     auto t = min_heap.top();
        //     if (t.next_cooldown_time <= current_time) {
        //         min_heap.pop();
        //         remained[t.id] -= 1;
        //         if (remained[t.id] > 0) {
        //             // push to heap
        //             t.next_cooldown_time = current_time + n + 1;
        //             min_heap.push(t);
        //         }
        //         current_time += 1;
        //     } else {
        //         current_time = t.next_cooldown_time; // fast forward
        //         min_heap.pop();
        //         remained[t.id] -= 1;
        //         if (remained[t.id] > 0) {
        //             // push to heap
        //             t.next_cooldown_time = current_time + n + 1;
        //             min_heap.push(t);
        //         }
        //         current_time += 1;
        //     }
        // }

        // Instead, we need to process the MORE frequent task first:
        // Put all cnts into max heap (i.e. tasks ready for processed )
        // once processed -> move from max heap to cool down queue (not ready for processed)
        // once cooled down -> move back to max heap
        queue<pair<int, int>> cooldown_q; // freq, timestamp
        while (!max_freq_heap.empty() || !cooldown_q.empty()) {
            current_time += 1;

            if (!max_freq_heap.empty()) {
                auto freq = max_freq_heap.top();
                max_freq_heap.pop();
                freq -= 1;
                if (freq > 0) {
                    cooldown_q.push(make_pair(freq, current_time + n));
                }
            }

            if (!cooldown_q.empty() && cooldown_q.front().second == current_time) {
                auto p = cooldown_q.front();
                cooldown_q.pop();
                max_freq_heap.push(p.first);
            }
        }

        return current_time;

    }
};
