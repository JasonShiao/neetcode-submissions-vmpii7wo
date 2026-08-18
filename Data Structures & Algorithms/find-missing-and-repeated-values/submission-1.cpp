class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(2, -1);
        vector<int> lookup(n*n+1, 0);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                lookup[grid[r][c]] += 1;
                if (lookup[grid[r][c]] == 2) {
                    res[0] = grid[r][c];
                }
            }
        }

        for (int i = 1; i <= n*n; i++) {
            if (lookup[i] == 0) {
                res[1] = i;
                break;
            }
        }
        return res;
    }
};