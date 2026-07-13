/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        // Check each row and find the left-most 1 among all rows
        
        int COLS = binaryMatrix.dimensions()[1];
        int ROWS = binaryMatrix.dimensions()[0];
        auto bin_search = [&](int row_idx){
            int l = 0;
            int r = COLS - 1;

            int res = -1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (binaryMatrix.get(row_idx, m) == 1) {
                    // search left
                    res = m;
                    r = m - 1;
                } else {
                    // search right
                    l = m + 1;
                }
            }

            return res;
        };

        int ret = INT_MAX;
        for (int i = 0; i < ROWS; i++) {
            int cand = bin_search(i);
            if (cand == -1) {
                // skip
            } else {
                ret = min(cand, ret);
            }
        }

        if (ret == INT_MAX) {
            return -1;
        }

        return ret;
    }
};
