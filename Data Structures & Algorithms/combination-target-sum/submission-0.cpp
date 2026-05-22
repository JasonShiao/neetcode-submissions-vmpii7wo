class Solution {
public:
    void backtrack(vector<int>& nums, 
            int i, int target, 
            vector<vector<int>>& res,
            vector<int>& curr_subset) {
        if (target == 0) { // find a correct subset, terminate early
            res.push_back(curr_subset);
            return;
        } else if (target < 0) { // impossible to find, terminate early
            return;
        }
        if (i == nums.size()) {
            return;
        }

        // if include i, can choose next val from nums [i:]
        // if exclude i, can choose next val from nums [i+1:]

        // exclude i
        backtrack(nums, i+1, target, res, curr_subset);
        // include i
        target -= nums[i];
        curr_subset.push_back(nums[i]);
        backtrack(nums, i, target, res, curr_subset);
        // remove current num for backtracking after process
        curr_subset.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr_subset;
        backtrack(nums, 0, target, res, curr_subset);

        return res;
    }
};
