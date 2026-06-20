typedef tuple<int, int, int> cell;

struct MinCell {
    bool operator()(cell a, cell b) {
        return get<0>(a) > get<0>(b);
    };
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // only use maximum instead of sum
        // Cf. shortest path problem for weighted-edge graph

        // Greedy: always explore 
        //         the current (unprocessed/unvisited) min diff cell
        //   use a min heap to store the 
        //   max diff of min-effort path from (0, 0) to (r, c)
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<int>> dirs = 
            {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        priority_queue<cell, vector<cell>, MinCell> min_heap;
        // can't use non-primitive type for unordered_set
        //unordered_set<pair<int, int>> visited;
        vector<vector<bool>> visited(ROWS, 
            vector<bool>(COLS, false));

        min_heap.push(make_tuple(0, 0, 0));

        while (!min_heap.empty()) {
            // get and pop the front (current min)
            auto t = min_heap.top();
            min_heap.pop();

            int r = get<1>(t);
            int c = get<2>(t);
            if (visited[r][c]) {
                continue;
            }

            if (r == (ROWS - 1) && c == (COLS - 1)) {
                return get<0>(t);
            }

            // mark processed cell as visited
            visited[r][c] = true;

            // explore neighbor
            for (auto dir: dirs) {
                int new_r = r + dir[0];
                int new_c = c + dir[1];
                if (new_r < 0 || new_c < 0 || new_r >= ROWS || new_c >= COLS
                    || visited[new_r][new_c]) {
                    continue;
                }

                // determine the diff for new cell: max(curr_cell_diff, new_diff)
                int diff = max(get<0>(t), 
                                abs(heights[r][c] - heights[new_r][new_c]));

                min_heap.push(make_tuple(diff, new_r, new_c));

            }

        }

        return 0;

    }
};