class Solution {
public:
    void dfsArea(const vector<vector<int>>& grid, 
            vector<vector<bool>>& visited,
            int r, int c,
            int& area) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            return;
        }
        if (grid[r][c] == 0 || visited[r][c]) {
            return;
        }

        area += 1;
        visited[r][c] = true; // Remember to mark visited !!
        dfsArea(grid, visited, r - 1, c, area);
        dfsArea(grid, visited, r + 1, c, area);
        dfsArea(grid, visited, r, c - 1, area);
        dfsArea(grid, visited, r, c + 1, area);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (auto r = 0; r < grid.size(); r++) {
            for (auto c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    int area = 0;
                    dfsArea(grid, visited, r, c, area);
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }

        return max_area;
    }
};
