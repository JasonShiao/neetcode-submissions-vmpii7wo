class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> max_heap;
        // Initialize: push to heap first
        for (auto g: gifts) {
            max_heap.push(g);
        }

        for (int i = 0; i < k; i++) {
            auto p = max_heap.top();
            max_heap.pop();

            p = sqrt(p);
            max_heap.push(p);
        }

        // sum all remaining
        long long res = 0;
        while (!max_heap.empty()) {
            res += max_heap.top();
            max_heap.pop();
        }

        return res;
    }
};