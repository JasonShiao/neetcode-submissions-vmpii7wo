class Solution {
public:
    void backtrack(vector<int>& nums, int idx,
                   vector<int>& curr,
                   vector<vector<int>>& res) {
        // Only modify the final result (res) when a subset is complete
        if (idx == nums.size()) {
            res.push_back(curr);
            return;
        }

        // update only curr in intermediate layers

        // exclude nums[idx]
        backtrack(nums, idx + 1, curr, res);

        // include nums[idx]
        curr.push_back(nums[idx]);
        backtrack(nums, idx + 1, curr, res);
        curr.pop_back(); // backtrack
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;

        backtrack(nums, 0, curr, res);

        return res;
    }
};
