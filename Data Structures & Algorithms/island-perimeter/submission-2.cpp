class Solution {
public:
    // Key: insert to visited when push to queue instead of process
    int bfs(int r, int c, 
            unordered_set<int>& visited, 
            vector<vector<int>>& grid) {
        queue<pair<int, int>> pos_q;

        pos_q.push({r, c});
        visited.insert(r * grid[0].size() + c);

        int peri = 0;
        while (!pos_q.empty()) {
            auto cur_pos = pos_q.front();
            pos_q.pop();
            int pos_1D = cur_pos.first * grid[0].size() + cur_pos.second;

            int water_cnt = 0;
            vector<vector<int>> dirs = {
                {-1, 0}, {1, 0}, {0, -1}, {0, 1}
            };
            for (auto dir: dirs) {
                int neigh_r = cur_pos.first + dir[0];
                int neigh_c = cur_pos.second + dir[1];
                int neigh_pos_1D = neigh_r * grid[0].size() + neigh_c;
                if (min(neigh_r, neigh_c) < 0 || 
                    neigh_r >= grid.size() || neigh_c >= grid[0].size()) {
                    water_cnt += 1;
                } else if (visited.find(neigh_pos_1D) != visited.end()) {
                    continue;
                } else if (grid[neigh_r][neigh_c] == 0) {
                    water_cnt += 1;
                } else if (grid[neigh_r][neigh_c] == 1) {
                    visited.insert(neigh_pos_1D);
                    // push to queue
                    pos_q.push({neigh_r, neigh_c});
                }
            }
            peri += water_cnt;

        }

        return peri;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        // use a visited set to avoid repeat
        // DFS from any cell on the land
        int start_r = 0;
        int start_c = 0;
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    start_r = r;
                    start_c = c;
                    break;
                }
            }
        }
        
        unordered_set<int> visited;

        return bfs(start_r, start_c, visited, grid);
    }
};