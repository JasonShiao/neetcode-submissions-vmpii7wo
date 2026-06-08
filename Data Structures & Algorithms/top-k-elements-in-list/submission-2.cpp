class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_cnt;
        for (auto num: nums) {
            num_cnt[num] += 1;
        }

        // push all (int, freq) pair to heap
        priority_queue<pair<int, int>> max_freq_heap;
        for (auto [num, freq]: num_cnt) {
            max_freq_heap.push({freq, num});
        }

        vector<int> res;
        while (res.size() < k) {
            res.push_back(max_freq_heap.top().second);
            max_freq_heap.pop();
        }

        return res;
    }
};
