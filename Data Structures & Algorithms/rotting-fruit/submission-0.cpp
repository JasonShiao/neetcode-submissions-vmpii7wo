class Solution {
public:
    bool isValidNode(int r, int c, 
            int max_r, int max_c, 
            vector<vector<int>>& grid) {
        if (r >= max_r || 
            c >= max_c ||
            r < 0 || c < 0) {
            // invalid
            return false;
        }

        if (grid[r][c] != 1) {
            return false;
        }

        return true;
    }
    void bfs(int r, int c, 
            vector<vector<int>>& grid,
            vector<vector<int>>& rotten_time_table) {
        
        int next_time = rotten_time_table[r][c] + 1;
        //visited.insert({r, c});
        vector<pair<int, int>> neighbor_list = {
            {r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}
        };
        for (auto n: neighbor_list) {
            if (isValidNode(n.first, n.second, 
                            rotten_time_table.size(), rotten_time_table[0].size(),
                            grid)) {
                if (next_time < rotten_time_table[n.first][n.second]) { 
                    // only step into when updated
                    rotten_time_table[n.first][n.second] = next_time;
                    bfs(n.first, n.second, grid, rotten_time_table);
                }
            }
        }
        //visited.remove({r, c});
    }

    int orangesRotting(vector<vector<int>>& grid) {
        // Start from each cell that is 2 (rotten)
        // shortest path to any 1 (fresh)

        // initialize
       vector<vector<int>> rotten_time_table(
            grid.size(), vector<int>(grid[0].size(), 0));
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    rotten_time_table[r][c] = INT_MAX;
                } else if (grid[r][c] == 0) {
                    rotten_time_table[r][c] = -1;
                }
            }
        }

        // start from each rotten
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) { // start from a rotten
                    bfs(r, c, grid, rotten_time_table);
                }
            }
        }

        // find the max value for fresh cell
        int max_time = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] != 1) {
                    continue;
                }
                if (rotten_time_table[r][c] > max_time) {
                    max_time = rotten_time_table[r][c];
                }
            }
        }
        return max_time == INT_MAX ? -1 : max_time;

    }
};
