class Solution {
public:
    // First intuition (dfs from each cell) doesn't work 
    // -> because the "equal height" will introduce a cycle
    //    and both cell depend on each other

    // Instead, we should start from cell directlt connect to the ocean
    // and dfs
        int rows, cols;

    void dfs(vector<vector<int>>& heights,
             vector<vector<bool>>& ocean,
             int r, int c) {
        ocean[r][c] = true;

        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;

            if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) {
                continue;
            }

            if (ocean[nr][nc]) {
                continue;
            }

            // reverse flow: ocean can reach higher/equal cells
            if (heights[nr][nc] >= heights[r][c]) {
                dfs(heights, ocean, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            dfs(heights, pacific, r, 0);
            dfs(heights, atlantic, r, cols - 1);
        }

        for (int c = 0; c < cols; c++) {
            dfs(heights, pacific, 0, c);
            dfs(heights, atlantic, rows - 1, c);
        }

        vector<vector<int>> res;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    res.push_back({r, c});
                }
            }
        }

        return res;
    }
};
