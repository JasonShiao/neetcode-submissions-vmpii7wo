class Solution {
public:
    void dfs_visit(vector<vector<char>>& grid, int r, int c, 
        vector<vector<bool>>& visited) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            return;
        }
        if (grid[r][c] == '0' || visited[r][c] == true) {
            return;
        }
        visited[r][c] = true;

        dfs_visit(grid, r + 1, c, visited);
        dfs_visit(grid, r - 1, c, visited);
        dfs_visit(grid, r, c + 1, visited);
        dfs_visit(grid, r, c - 1, visited);

    }
    int numIslands(vector<vector<char>>& grid) {
        
        int cnt = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for (auto i = 0; i < grid.size(); i++) {
            for (auto j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) { // a new island
                    cnt += 1;
                    dfs_visit(grid, i, j, visited);
                }
            }
        }

        return cnt;
    }
};
