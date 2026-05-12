class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        for (auto c = 0; c < matrix[0].size(); c++) {
            res.push_back(vector<int>{});
            for (auto r = 0; r < matrix.size(); r++) {
                res[c].push_back(matrix[r][c]);
            }
        }

        return res;
    }
};