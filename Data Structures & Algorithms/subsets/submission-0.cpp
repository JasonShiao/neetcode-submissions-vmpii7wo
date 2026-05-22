class Solution {
public:
    vector<vector<int>> recursiveSet(vector<int>& nums, int idx, vector<int>& curr_set) {
        vector<vector<int>> res;
        if (idx >= nums.size()) { // last element
            res.emplace_back(curr_set);
            return res;
        }
        
        // include the current idx
        vector<int> include_set = curr_set;
        include_set.push_back(nums[idx]);
        // exclude the current idx
        vector<int> exclude_set = curr_set;
        // get further subsets
        auto include_sets = recursiveSet(nums, idx + 1, include_set);
        auto exclude_sets = recursiveSet(nums, idx + 1, exclude_set);
        // merge
        include_sets.insert(include_sets.end(), 
                            exclude_sets.begin(), 
                            exclude_sets.end());
        return include_sets;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // At each fork: include num or not include num
        vector<int> empty_set;
        auto res = recursiveSet(nums, 0, empty_set);
        return res;
    }
};
