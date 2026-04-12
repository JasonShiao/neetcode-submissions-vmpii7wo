class Solution {
public:
    int uniquePaths(int m, int n) {
        int result = 0;
        // save memory by modify in place
        vector<int> prev_row(n, 0);
        // row by row
        for (int i = m-1; i >= 0; i--) {
            // declare and assign 1 to the right-most grid
            prev_row[n-1] = 1;
            // iterate and fill from right to left
            for (int j = n-2; j >= 0; j--) {
                prev_row[j] += prev_row[j+1];
            }
        }

        // return the last top-left in grid
        return prev_row[0];
    }
};
