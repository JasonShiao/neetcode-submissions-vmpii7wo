struct Obj {
    int dist;
    int worker_idx;
    int bike_idx;
};

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        // Brute force: O(m*n) -> O(n^2)
        
        // Merge the "shortest dist pair first"!! 
        // instead of for each bike, scan through all remaining workers
        // but since n <= m -> at most n bikes will be matched
        auto cmp = [](const Obj& a, const Obj& b) {
            if (a.dist < b.dist) {
                return false;
            } else if (a.dist > b.dist) {
                return true;
            }

            if (a.worker_idx < b.worker_idx) {
                return false;
            } else if (a.worker_idx > b.worker_idx) {
                return true;
            }

            if (a.bike_idx < b.bike_idx) {
                return false;
            } else {
                return true;
            }
        };

        // O(n^2 log(n^2)) = O(n^2 logn)
        priority_queue<Obj, vector<Obj>, decltype(cmp)> min_heap;
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                min_heap.push(Obj{abs(workers[i][0] - bikes[j][0]) + 
                                abs(workers[i][1] - bikes[j][1]), i, j});
            }
        }

        // 1. min heap of pair
        // 2. a set of workers marked assigned
        vector<int> res(workers.size(), 0);
        unordered_set<int> assigned_workers;
        unordered_set<int> assigned_bikes;
        while (assigned_workers.size() < workers.size()) {
            auto o = min_heap.top();
            min_heap.pop();
            if (assigned_workers.find(o.worker_idx) != assigned_workers.end()) {
                // already assigned -> skip
            } else if (assigned_bikes.find(o.bike_idx) != assigned_bikes.end()) {
                // already assigned -> skip
            } else {
                res[o.worker_idx] = o.bike_idx;
                assigned_workers.insert(o.worker_idx);
                assigned_bikes.insert(o.bike_idx);
            }
        }

        return res;
    }
};
