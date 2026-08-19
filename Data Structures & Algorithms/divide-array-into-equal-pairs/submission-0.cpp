class Solution {
public:
    bool divideArray(vector<int>& nums) {
        // use a set to store the value occurs in non-pair
        // once a value appear to form a pair, remove it from the set

        unordered_set<int> non_paired_val;
        for (auto num: nums) {
            if (non_paired_val.find(num) == non_paired_val.end()) {
                non_paired_val.insert(num);
            } else {
                non_paired_val.erase(num);
            }
        }
        
        return non_paired_val.empty();
    }
};