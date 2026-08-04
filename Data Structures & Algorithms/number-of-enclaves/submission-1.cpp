class Solution {
public:
    int find_enclave(int r, int c, 
                    vector<vector<int>>& grid, 
                    vector<vector<bool>>& visited) {
        int cnt = 0;

        // BFS from {r, c}
        bool valid = true; // if any border cell -> invalid component
        deque<pair<int, int>> dq;
        dq.push_back({r, c});
        visited[r][c] = true;
        while (!dq.empty()) {
            auto cell = dq.front();
            dq.pop_front();

            cnt += 1; // cells in the connected graph

            // NOTE: cell on the queue is always a land (1)
            // if reach border -> a valid connected component!
            if (cell.first == 0 || cell.first == grid.size() - 1 ||
                cell.second == 0 || cell.second == grid[0].size() - 1) {
                valid = false;
            }
            const vector<vector<int>> dirs = {
                {0, 1}, {0, -1}, {1, 0}, {-1, 0}
            };
            for (auto dir: dirs) {
                int nrow = cell.first + dir[0];
                int ncol = cell.second + dir[1];
                // out of grid
                if (nrow < 0 || nrow >= grid.size() ||
                    ncol < 0 || ncol >= grid[0].size()) {
                    continue;
                }
                // sea cell
                if (grid[nrow][ncol] == 0) {
                    continue;
                }
                // visited
                if (visited[nrow][ncol]) {
                    continue;
                }
                dq.push_back({nrow, ncol});
                visited[nrow][ncol] = true;
            }
        }

        if (valid) {
            return cnt;
        } else {
            return 0;
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // Find cell that is belong to a 
        // connected component of 1s && touch the grid border
        int total_enclave = 0;

        vector<vector<bool>> visited(grid.size(), 
                    vector<bool>(grid[0].size(), false));

        for (int r = 1; r < grid.size() - 1; r++) {
            for (int c = 1; c < grid[0].size() - 1; c++) {
                if (visited[r][c] || grid[r][c] == 0) {
                    continue;
                }

                int num_cell = find_enclave(r, c, grid, visited);
                if (num_cell > 0) {
                    total_enclave += num_cell;
                }
            }
        }

        return total_enclave;
    }
};