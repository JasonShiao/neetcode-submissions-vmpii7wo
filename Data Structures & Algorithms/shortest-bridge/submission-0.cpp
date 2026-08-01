class Solution {
public:
    void dfs(vector<vector<int>>& grid, deque<vector<int>>& q,
            int r, int c, vector<vector<bool>>& visited) {
        q.push_back({r, c});
        visited[r][c] = true;
        const vector<vector<int>> dirs = { // neighbors
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        for (auto dir: dirs) {
            int nrow = r + dir[0];
            int ncol = c + dir[1];
            if (nrow >= 0 && nrow < grid.size() &&
                ncol >= 0 && ncol < grid[0].size() &&
                 grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                dfs(grid, q, nrow, ncol, visited);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        // BFS from each island

        // 1. DFS to find all cells for one island
        vector<vector<bool>> visited(grid.size(), 
            vector<bool>(grid[0].size(), false));
        deque<vector<int>> q; // {r, c}
        bool early_break_dfs = false;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid.size(); c++) {
                if (grid[r][c] == 1) {
                    // only need one island
                    dfs(grid, q, r, c, visited);
                    early_break_dfs = true;
                    break;
                }
            }
            if (early_break_dfs) {
                break;
            }
        }

        // 2. BFS with initialized queue
        int depth = 0;
        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; i++) {
                auto p = q.front();
                q.pop_front();

                // already marked visited when pushed

                // check neighbors
                const vector<vector<int>> dirs = { // neighbors
                    {0, 1},
                    {0, -1},
                    {1, 0},
                    {-1, 0}
                };
                // check and enqueue neighbors
                for (auto dir: dirs) {
                    int nrow = p[0] + dir[0];
                    int ncol = p[1] + dir[1];
                    // reject invalid cell
                    if (nrow < 0 || nrow >= grid.size() ||
                        ncol < 0 || ncol >= grid[0].size()) {
                        continue;
                    }
                    if (visited[nrow][ncol]) {
                        continue; // visited -> skip
                    }

                    if (grid[nrow][ncol] == 0) {
                        // enqueue the water cell for explore further
                        // NOTICE: remember to update visited!!
                        visited[nrow][ncol] = true;
                        q.push_back({nrow, ncol});
                    } else {
                        // found the other island -> return the distance
                        return depth;
                    }
                }
            }
            depth += 1;
        }

        return 0;
    }
};