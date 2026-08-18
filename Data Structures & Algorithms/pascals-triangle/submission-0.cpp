class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                res.push_back({1});
                continue;
            } else if (i == 1) {
                res.push_back({1, 1});
                continue;
            }

            // curr row generated from the last row
            vector<int> curr_row;
            curr_row.push_back(1);
            for (int j = 0; j < res.back().size() - 1; j++) {
                curr_row.push_back(res.back()[j] + res.back()[j+1]);
            }
            curr_row.push_back(1);
            res.emplace_back(curr_row);
        }

        return res;
    }
};