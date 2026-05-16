class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Tips: different from transpose: col order is reversed
        //     transpose: swap (i, j) and (j, i)
        // Tips: square matrix -> no need to handle mismatch size of row & col
        // Target: O(1) space, O(n^2) time

        // four-way swap:
        // (i, j) to (j, N - i - 1)
        // (j, N - i - 1) to (N - i - 1, N - j - 1)
        // (N - i - 1, N - j - 1) to (N - j - 1, i)
        // (N - j - 1, i) to (i, j)
        // NOTICE: cannot "swap" lower/upper triangle directly
        int N = matrix.size();
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = i; j < matrix.size() - i - 1; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[N - j - 1][i];
                matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1];
                matrix[N - i - 1][N - j - 1] = matrix[j][N - i - 1];
                matrix[j][N - i - 1] = temp;
            }
        }
        
    }
};
