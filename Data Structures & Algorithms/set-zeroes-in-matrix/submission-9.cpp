class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Approach 1: relatively easy to achieve O(m+n) space by lookup table
        //vector<bool> row_lookup(matrix.size(), false);
        //vector<bool> col_lookup(matrix[0].size(), false);

        // Tricky technique: put the lookup into the matrix's first row and first col

        bool first_row_zero = false;
        bool first_col_zero = false;
        // first round: fill the lookup (NOTICE: exclude the first row & col)
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                // special handle the first row and first col
                if (i == 0 && j == 0) {
                    if (matrix[i][j] == 0) {
                        first_row_zero = true;
                        first_col_zero = true;
                    }
                    continue;
                } else if (i == 0) { // the first row
                    if (matrix[i][j] == 0) {
                        first_row_zero = true;
                    }
                    continue;
                } else if (j == 0) {
                    if (matrix[i][j] == 0) {
                        first_col_zero = true;
                    }
                    continue;
                }

                // normal handle
                if (matrix[i][j] == 0) {
                    // row_lookup[i] = true;
                    // col_lookup[j] = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // second round: apply the lookup (NOTICE: exclude the first row & col)
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || 
                    matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // Tricky: check first row and first col
        //         since it might be set
        // first row
        if (first_row_zero) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
        if (first_col_zero) {
            for (int j = 0; j < matrix.size(); j++) {
                matrix[j][0] = 0;
            }
        }

    }
};
