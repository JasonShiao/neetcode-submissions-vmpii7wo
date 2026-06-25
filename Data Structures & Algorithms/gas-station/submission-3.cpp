class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Alternative: Greedy approach
        // Insight: 
        //    -1 only when sum(gas) < sum(cost)
        int sum_gas = accumulate(gas.begin(), gas.end(), 0);
        int sum_cost = accumulate(cost.begin(), cost.end(), 0);
        if (sum_gas < sum_cost) {
            return -1;
        }
        // An valid answer is guaranteed,
        // Iterate and accumulate, if < 0, start from next (set total to 0)
        int start = 0;
        int total = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);
            if (total < 0) {
                start = i + 1;
                total = 0;
            }
        }
        return start;


        // Calculate diff of gas and cost
        // candidate starts are 
        //    indices with diff just transit from (prev) negative to positive
        // accumulate positive and fill the negative on the right

        // 0. Build diff vector
        // 1. find transition from neg to pos at the same time
        vector<int> diff(gas.size(), 0);
        queue<int> cand_start;
        for (int i = 0; i < gas.size(); i++) {
            diff[i] = gas[i] - cost[i];
            if (i > 0 && diff[i-1] < 0 && diff[i] > 0) {
                cand_start.push(i);
            }
        }
        // handle circular for start
        if (diff[0] > 0 && diff[diff.size() - 1] < 0) {
            cand_start.push(0);
        }

        // edge case: only 1 element
        if (diff.size() == 1) {
            if (diff[0] >= 0) {
                return 0;
            } else {
                return -1;
            }
        }
        
        // test each possible start, 
        // if not pass, remove it from cand list
        unordered_map<int, pair<int, int>> merged_station; // start idx -> <end idx, accum_diff>
        while (!cand_start.empty()) {
            auto start_idx = cand_start.front();
            cand_start.pop();
            int accum_diff = diff[start_idx];
            int prev_idx = start_idx;
            int cur_idx = (prev_idx + 1) % diff.size();
            while (cur_idx != start_idx) {
                if (merged_station.find(cur_idx) != merged_station.end()) {
                    // fast forward (reuse the previous work)
                    accum_diff += merged_station[cur_idx].second;
                    prev_idx = merged_station[cur_idx].first;
                    cur_idx = (merged_station[cur_idx].first + 1) % diff.size();
                } else {
                    if ((accum_diff + diff[cur_idx]) < 0) {
                        // failed but record the work
                        merged_station[start_idx] = {prev_idx, accum_diff};
                        break;
                    }
                    accum_diff += diff[cur_idx];
                    prev_idx = cur_idx;
                    cur_idx = (cur_idx + 1) % diff.size();
                }
            }

            if (cur_idx == start_idx) {
                return start_idx;
            }
        }

        return -1;

    }
};
