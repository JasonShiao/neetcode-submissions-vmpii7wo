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
        // time complexity: O(n^n) (if "continue" isn't efficient)
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

        // Bottom up approach:
        //   Given the permutations from subset of nums,
        //   insert the missing num to every possible position

        // if (nums.size() == 0) {
        //     return vector<vector<int>>{};
        // }
        // auto perms = this->permute(vector<int>(nums.begin() + 1, v.end()));
        // vector<vector<int>> res;
        // for (auto p: perms) {
        //     for (int i = 0; i < (p.size() + 1); i++) {
        //         p.insert(i, nums[0]);
        //         p_copy insert(i, nums [®])
        //     }
        // }

    }
};
