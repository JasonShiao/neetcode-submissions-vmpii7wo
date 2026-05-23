class Solution {
public:
    void backtrack(vector<int>& candidates, int i, 
            vector<vector<int>>& res, vector<int>& combination,
            int target) {
        if (target == 0) {
            res.push_back(combination);
            return;
        } else if (target < 0) {
            return;
        }
        if (i == candidates.size()) {
            return;
        }

        // Critical part:
        // exclude i -> skip all remaining duplicate
        int next_non_dup = i + 1;
        while (next_non_dup < candidates.size() && 
            candidates[next_non_dup] == candidates[i]) {
            next_non_dup += 1;
        }
        backtrack(candidates, next_non_dup, res, combination, target);

        // include i -> 
        combination.push_back(candidates[i]);
        target -= candidates[i];
        backtrack(candidates, i + 1, res, combination, target);
        combination.pop_back();

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort first to make duplicate near each other
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> combination;

        backtrack(candidates, 0, res, combination, target);

        return res;
    }
};
