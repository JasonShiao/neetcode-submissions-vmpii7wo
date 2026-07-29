class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // Approach 1: additional storage for each col and each row
        // Possible trick: reuse the first row and first col to save extra storage
        vector<int> row_cnt(grid.size(), 0); // cnt of server at i-th row
        vector<int> col_cnt(grid[0].size(), 0); // cnt of server at i-th col
        // Initialize
        for (auto r = 0; r < grid.size(); r++) {
            for (auto c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    row_cnt[r] += 1;
                    col_cnt[c] += 1;
                }
            }
        }

        // Check for each server
        int res = 0;
        for (auto r = 0; r < grid.size(); r++) {
            for (auto c = 0; c < grid[0].size(); c++) {
                if (grid[r][c] == 1) {
                    if (row_cnt[r] > 1 || col_cnt[c] > 1) {
                        res += 1;
                    }
                }
            }
        }
        return res;
    }
};