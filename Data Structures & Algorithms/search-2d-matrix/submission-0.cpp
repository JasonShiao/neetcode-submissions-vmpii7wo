class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // key: how to we find the half pos from the 2D
        //      -> convert to 1D idx
        //         1d_idx = row_idx * n_col + col_idx
        //         row_idx = 1d_idx / n_col;
        //         col_idx = 1d_idx % n_col;
        int left = 0;
        int right = matrix.size() * matrix[0].size() - 1;
        int n_row = matrix.size();
        int n_col = matrix[0].size();
        
        if (target < matrix[0][0]) {
            return false;
        } else if (target > (matrix.back()).back() ) {
            return false;
        }

        while (left <= right) {
            int half = (left + right) / 2;

            // convert half 1d -> row, col
            int row_idx = half / n_col;
            int col_idx = half % n_col;
            if (matrix[row_idx][col_idx] == target) {
                return true;
            } else if (matrix[row_idx][col_idx] < target) {
                // update left to half
                left = half + 1;
            } else {
                right = half - 1;
            }

        }
        
        return false;

    }
};
