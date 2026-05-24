class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> window_lookup;
        // initialize the window of size k
        k += 1; // adjust for my implementation
        for (int i = 0; i < min((int)nums.size(), k); i++) {
            if (window_lookup.find(nums[i]) != window_lookup.end() &&
                window_lookup[nums[i]] > 0) {
                return true;
            }
            window_lookup[nums[i]] += 1;
        }

        for (int i = k; i < nums.size(); i++) {
            window_lookup[nums[i - k]] -= 1;
            if (window_lookup.find(nums[i]) != window_lookup.end() &&
                window_lookup[nums[i]] > 0) {
                return true;
            }
            window_lookup[nums[i]] += 1;
        }

        return false;
    }
};