class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
       // the 3. Row Position solution is more intuitive
       // find the current_max value seen 
       // For each row, advance pointer until it is larger than the current_max

        int cur_max = -1;
        // initialize
        for (int i = 0; i < mat.size(); i++) {
            if (mat[i][0] > cur_max) {
                cur_max = mat[i][0];
            }
        }

        // cursor for each row
        vector<int> cursors(mat.size(), 0);

        while (true) {
            bool updated = false;
            for (int i = 0; i < mat.size(); i++) {
                // move until >= cur_max
                while (cursors[i] < mat[i].size() &&
                        mat[i][cursors[i]] < cur_max) {
                    cursors[i] += 1;
                }
                // early break (failure case)
                if (cursors[i] == mat[i].size()) {
                    return -1;
                }

                if (mat[i][cursors[i]] > cur_max) {
                    cur_max = mat[i][cursors[i]];
                    updated = true;
                }
            }

            // if no any updated in all rows -> found the answer
            if (!updated) {
                return cur_max;
            }

        }

        return -1;
    }
};
