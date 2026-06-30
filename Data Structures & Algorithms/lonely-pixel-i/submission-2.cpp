class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        // count the black in each cols[i]
        // count the black in each rows[i]

        vector<int> rows_cnt(picture.size(), 0);
        vector<int> cols_cnt(picture[0].size(), 0);

        for (int r = 0; r < picture.size(); r++) {
            for (int c = 0; c < picture[0].size(); c++) {
                if (picture[r][c] == 'B') {
                    rows_cnt[r] += 1;
                    cols_cnt[c] += 1;
                }
            }
        }

        // 2nd pass
        int res = 0;
        for (int r = 0; r < picture.size(); r++) {
            for (int c = 0; c < picture[0].size(); c++) {
                // NOTICE: assert pixel 'B' is necessary!!!
                if (picture[r][c] == 'B' && 
                    rows_cnt[r] == 1 && cols_cnt[c] == 1) {
                    res += 1;
                }
            }
        }

        return res;

    }
};
