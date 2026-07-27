class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        // Non accumulated metrics -> not always go right or down
        // -> Cannot use dynamic programming! 

        // Insight: Always select the neighbor with max value!
        //          using Maxheap
        // Also use a visited set/map to reject reentering
        set<pair<int, int>> visited;
        auto cmp = [](tuple<int, int ,int>& a, tuple<int, int ,int>& b) {
            if (get<0>(a) >= get<0>(b)) {
                return false; // a first
            } else if (get<0>(a) < get<0>(b)) {
                return true;
            }
            return false;
        };

        priority_queue<tuple<int, int ,int>, 
                    vector<tuple<int, int ,int>>, 
                    decltype(cmp)> max_heap;
        // Push the initial element into max heap
        int res = INT_MAX;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        max_heap.push(make_tuple(grid[0][0], 0, 0));
        // update visited when pushing to queue 
        // (if update in process, some node will still be visited twice!)
        visited.insert({0, 0});
        while (!max_heap.empty()) {
            auto tup = max_heap.top();
            max_heap.pop();

            int curr_row = get<1>(tup);
            int curr_col = get<2>(tup);
            res = min(res, get<0>(tup));
            // check
            if ((curr_row == ROWS - 1) && (curr_col == COLS - 1)) {
                // the final dest is the min val in path
                return res;
            }

            // push neighbors
            vector<vector<int>> neighbors = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto n: neighbors) {
                int nrow = curr_row + n[0];
                int ncol = curr_col + n[1];
                if (nrow < ROWS && nrow >= 0 && ncol >= 0 && ncol < COLS &&
                    visited.find({nrow, ncol}) == visited.end()) {
                    max_heap.push(make_tuple(grid[nrow][ncol], nrow, ncol));
                    visited.insert({nrow, ncol});
                }
            }
        }

        return 0;
    }
};
