class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<tuple<int, int>> q;
        vector<vector<bool>> visited(grid.size(), 
                                    vector<bool>(grid[0].size(), false));
        // add first node
        q.push(make_tuple<int, int>(0, 0));
        int length = 1;
        while (q.size() > 0) {
            // for selecting nodes correspond to the same length dist
            int q_curr_size = q.size();
            for (int i = 0; i < q_curr_size; i++) {
                auto node_tup = q.front();
                int row = get<0>(node_tup);
                int col = get<1>(node_tup);
                q.pop();

                // skip invalid
                if (visited[row][col]) {
                    continue;
                }
                if (grid[row][col] == 1) {
                    continue;
                }
                // check success condition reached
                if ((row == grid.size() - 1) && (col == grid[0].size() - 1)) {
                    return length;
                }
                
                visited[row][col] = true; // mark visited

                // append adjacent nodes to queue
                vector<tuple<int, int>> adj_dist = {
                    {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, 
                    {0, 1}, {1, -1}, {1, 0}, {1, 1}};
                for (auto& adj: adj_dist) {
                    int dr = get<0>(adj);
                    int dc = get<1>(adj);
                    if (row + dr < 0 || col + dc < 0 || 
                        row + dr >= grid.size() || col + dc >= grid[0].size()) {
                        continue;
                    }
                    q.push(make_tuple<int, int>(row + dr, col + dc));
                }

            }
            length += 1;
        }

        return -1;
    }
};