class NumMatrix {
private:
    vector<vector<int>> corner_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        corner_sum.resize(matrix.size(), vector<int>(matrix[0].size()));

        // fill upper-left corner sum
        for (auto r = 0; r < matrix.size(); r++) {
            int row_accum_sum = 0;
            for (auto c = 0; c < matrix[0].size(); c++) {
                row_accum_sum += matrix[r][c];
                if (r == 0) {
                    corner_sum[r][c] = row_accum_sum;
                } else {
                    corner_sum[r][c] = row_accum_sum + corner_sum[r-1][c];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int area1 =  corner_sum[row2][col2];
        int area2 = row1 > 0 ? corner_sum[row1 - 1][col2] : 0;
        int area3 = col1 > 0 ? corner_sum[row2][col1 - 1] : 0;
        int area4 = (row1 > 0 && col1 > 0) ? corner_sum[row1 - 1][col1 - 1] : 0;
        return area1 - area2 - area3 + area4;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */