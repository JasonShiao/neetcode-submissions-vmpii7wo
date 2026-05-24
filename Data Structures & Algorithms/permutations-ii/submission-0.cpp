class Solution {
public:
    void backtrack(vector<int>& nums,
        vector<vector<int>>& res, vector<int>& perm,
        unordered_map<int, int>& remaining) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        // loop through each key
        for (auto [key, cnt]: remaining) {
            if (cnt == 0) continue;

            remaining[key] -= 1;
            perm.push_back(key);
            backtrack(nums, res, perm, remaining);
            perm.pop_back(); // recover for the upper layer
            remaining[key] += 1;
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // Cf: No duplicate num in permutation I
        // -> Cannot use the insert approach!

        unordered_map<int, int> remaining;
        // build the remaining map
        for (auto n: nums) {
            remaining[n] += 1;
        }

        // Strategy:
        //  Cf. subset duplicate,
        //    we cannot fast forward for dup if not include n for this problem
        //  Incorrect: if not include -> skip all the same numbers for "the next pos"
        //  Correct: if include a num, dec in the remaining hash map,
        //    pass to the next layer 
        vector<vector<int>> res;
        vector<int> perm;
        backtrack(nums, res, perm, remaining);

        return res;
    }
};