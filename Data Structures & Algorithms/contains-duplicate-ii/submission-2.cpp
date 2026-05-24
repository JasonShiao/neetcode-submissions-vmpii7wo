class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // use set instead of map (hash table)
        unordered_set<int> window_lookup;
        // initialize the window of size k
        k += 1; // adjust for my implementation
        for (int i = 0; i < min((int)nums.size(), k); i++) {
            if (window_lookup.find(nums[i]) != window_lookup.end()) {
                return true;
            }
            window_lookup.insert(nums[i]);
        }

        for (int i = k; i < nums.size(); i++) {
            window_lookup.erase(nums[i - k]);
            if (window_lookup.find(nums[i]) != window_lookup.end()) {
                return true;
            }
            window_lookup.insert(nums[i]);
        }

        return false;
    }
};