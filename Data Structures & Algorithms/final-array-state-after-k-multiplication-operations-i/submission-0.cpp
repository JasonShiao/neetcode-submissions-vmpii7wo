class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first < b.first) {
                return false;
            } else if (a.first > b.first) {
                return true;
            } else {
                if (a.second < b.second) {
                    return false;
                } else {
                    return true;
                }
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap;
        for (auto i = 0; i < nums.size(); i++) {
            min_heap.push({nums[i], i});
        }
        
        // Perform k operations
        for (auto i = 0; i < k; i++) {
            auto p = min_heap.top();
            min_heap.pop();

            p.first = p.first * multiplier;
            min_heap.push(p);
        }

        vector<int> res(nums.size(), 0);
        while (!min_heap.empty()) {
            auto p = min_heap.top();
            min_heap.pop();
            res[p.second] = p.first;
        }
        return res;
    }
};