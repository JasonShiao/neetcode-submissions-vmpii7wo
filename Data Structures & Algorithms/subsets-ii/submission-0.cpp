class Solution {
public:
    void backtrack(vector<int>& nums, int i,
            vector<vector<int>>& res, vector<int>& subset) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        // exclude i, also skip all remaining dup
        int next_i = i + 1;
        while ((next_i) < nums.size() && nums[next_i] == nums[i]) {
            next_i += 1;
        }
        backtrack(nums, next_i, res, subset);

        // include i
        subset.push_back(nums[i]);
        backtrack(nums, i + 1, res, subset);
        subset.pop_back();

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort first to handle duplicate
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> subset;

        backtrack(nums, 0, res, subset);

        return res;
    }
};
