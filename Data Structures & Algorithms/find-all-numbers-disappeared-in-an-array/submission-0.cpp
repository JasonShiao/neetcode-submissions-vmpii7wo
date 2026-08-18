class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //
        int n = nums.size();
        unordered_set<int> missing;
        // first add all to missing 
        for (int i = 1; i <= n; i++) {
            missing.insert(i);
        }

        // iterate and remove from missing
        for (auto num: nums) {
            missing.erase(num);
        }
        // convert from set to vec
        vector<int> res;
        for (auto num: missing) {
            res.push_back(num);
        }
        return res;
    }
};