class Solution {
public:
    int uniquePaths(int m, int n) {
        int result = 0;
        vector<int> prev_row(n, 0);
        // row by row
        for (int i = m-1; i >= 0; i--) {
            // declare and assign 1 to the right-most grid
            vector<int> curr_row(n, 0);
            curr_row[n-1] = 1;

            // iterate and fill from right to left
            for (int j = n-2; j >= 0; j--) {
                curr_row[j] = prev_row[j] + curr_row[j+1];
            }

            // update prev_row with curr_row
            prev_row = curr_row;
        }
        
        // return the last top-left in grid
        return prev_row[0];
    }
};
