class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Start from each cell that is 2 (rotten)
        // shortest path to any 1 (fresh)

        // NOTICE: the nodes in the node_q are "the latest rotten" nodes
        //       instead of the fresh node
        queue<pair<int, int>> last_rotten_node_q;
        // start from each rotten -> add all to queue
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 2) { // start from a rotten
                    last_rotten_node_q.push({r, c});
                }
            }
        }

        // Process the queue
        int cur_time = 0;
        while (!last_rotten_node_q.empty()) {
            // Each while loop, process one entire layer of nodes
            int q_size = last_rotten_node_q.size();
            for (int i = 0; i < q_size; i++) { // these are nodes in the same layer
                auto node = last_rotten_node_q.front();
                last_rotten_node_q.pop(); // pop immediately after accessed

                // add all child nodes if valid
                vector<pair<int, int>> neighbor_list = {
                    {node.first+1, node.second}, {node.first-1, node.second}, 
                    {node.first, node.second+1}, {node.first, node.second-1}
                };
                for (auto n: neighbor_list) {
                    if (min(n.first, n.second) < 0 ||
                        n.first >= grid.size() || n.second >= grid[0].size()) {
                        // do nothing
                        continue;
                    }
                    if (grid[n.first][n.second] != 1) {
                        continue;
                    }
                    
                    // modify the current node to rotten
                    grid[n.first][n.second] = 2;
                    last_rotten_node_q.push({n.first, n.second});
                }
            }

            // If at least one layer next
            if (!last_rotten_node_q.empty()) {
                cur_time += 1;
            }
        }

        // find the max value for fresh cell
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) { // any fresh exists
                    return -1;
                }
            }
        }
        return cur_time;

    }
};
