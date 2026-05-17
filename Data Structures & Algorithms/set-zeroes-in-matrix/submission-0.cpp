class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // relatively easy to achieve O(m+n) space by lookup table
        vector<bool> row_lookup(matrix.size(), false);
        vector<bool> col_lookup(matrix[0].size(), false);

        // first round: fill the lookup
        for (auto i = 0; i < matrix.size(); i++) {
            for (auto j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row_lookup[i] = true;
                    col_lookup[j] = true;
                }
            }
        }
        // second round: apply the lookup
        for (auto i = 0; i < matrix.size(); i++) {
            for (auto j = 0; j < matrix[0].size(); j++) {
                if (row_lookup[i] == true || 
                    col_lookup[j] == true) {
                    matrix[i][j] = 0;
                }
            }
        }

    }
};
