class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        const int LAND = 2147483647;
        // BFS
        queue<vector<int>> last_updated_q;

        // start from all treasures -> push all treasure pos onto queue
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 0) {
                    last_updated_q.push({r,c});
                }
            }
        }

        int cur_dist = 1;
        while (!last_updated_q.empty()){
            int queue_size_snapshot = last_updated_q.size();
            // loop through one entire layer
            for (int i = 0; i < queue_size_snapshot; i++) {
                // explore the neighbor
                auto cur_pos = last_updated_q.front();
                last_updated_q.pop();
                vector<vector<int>> neighbors = {
                    {cur_pos[0] - 1, cur_pos[1]},
                    {cur_pos[0] + 1, cur_pos[1]},
                    {cur_pos[0], cur_pos[1]  - 1},
                    {cur_pos[0], cur_pos[1] + 1},
                };
                for (auto neigh: neighbors) {
                    // validate
                    if (min(neigh[0], neigh[1]) < 0 || 
                        neigh[0] >= grid.size() || neigh[1] >= grid[0].size()) {
                        continue;
                    }
                    if (grid[neigh[0]][neigh[1]] < LAND) {
                        // visited or water cell
                        continue;
                    }
                    // update and push to queue
                    grid[neigh[0]][neigh[1]] = cur_dist;
                    last_updated_q.push(neigh);
                }
            }
            cur_dist += 1;
        }

    }
};
