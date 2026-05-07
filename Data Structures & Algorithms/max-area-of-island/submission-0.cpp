class Solution {
public:
    int dfsArea(const vector<vector<int>>& grid, vector<vector<bool>>& visited,
        int r, int c) {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) {
            return 0;
        }
        if (grid[r][c] == 0 || visited[r][c]) {
            return 0;
        }

        int area = 1;
        visited[r][c] = true; // Remember to mark visited !!
        area += dfsArea(grid, visited, r - 1, c);
        area += dfsArea(grid, visited, r + 1, c);
        area += dfsArea(grid, visited, r, c - 1);
        area += dfsArea(grid, visited, r, c + 1);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (auto r = 0; r < grid.size(); r++) {
            for (auto c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1 && !visited[r][c]) {
                    int area = dfsArea(grid, visited, r, c);
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }

        return max_area;
    }
};
