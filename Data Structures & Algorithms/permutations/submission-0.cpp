class Solution {
public:
void backtrack(vector<int>& nums,
                   vector<bool>& used,
                   vector<int>& cur,
                   vector<vector<int>>& res) {
        if (cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }

        // Each layer has (n-k) branches
        // n, n-1, n-2, ..., 1 , 0: from top layer to bottom
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            cur.push_back(nums[i]);

            backtrack(nums, used, cur, res);

            cur.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // Incorrect intuition:
        // For each neighbor pair, two branches: swap or not swap
        // -> the order of swap matters!!!

        // Will be (n!) permutations
        // there are (n - i) branches
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(nums.size(), false); // Tips: this lookup is much simple

        backtrack(nums, used, cur, res);

        return res;

    }
};
