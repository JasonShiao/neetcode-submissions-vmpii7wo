class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        // For each student, build a max heap
        unordered_map<int, priority_queue<int>> heap_map;
        for (auto item: items) {
            heap_map[item[0]].push(item[1]);
        }

        // Pop 5 from each heap and avg and 
        // push the pair to another min_heap for sorting by ID purpose!!
        auto id_cmp = [](vector<int>& a, vector<int>& b) {
            if (a[0] < b[0]) {
                return false; // false: a comes first
            } else {
                return true;
            }
        };
        priority_queue<vector<int>, 
                    vector<vector<int>>, 
                    decltype(id_cmp)> min_id_heap;
        for (auto [id, heap]: heap_map) {
            int sum = 0;
            for (int i = 0; i < 5; i++) {
                sum += heap.top();
                heap.pop();
            }
            min_id_heap.push({id, sum / 5});
        }
        // pop the heap for result
        vector<vector<int>> res;
        while (!min_id_heap.empty()) {
            auto v = min_id_heap.top();
            min_id_heap.pop();
            res.push_back(v);
        }
        return res;
    }
};
