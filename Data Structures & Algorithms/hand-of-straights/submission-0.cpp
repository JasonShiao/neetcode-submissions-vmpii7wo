class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // build heap and a hash map for cnt
        unordered_map<int, int> cnt_map;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto val: hand) {
            cnt_map[val] += 1;
            if (cnt_map[val] == 1) {
                min_heap.push(val); // once for each value
            }
        }

        while (!min_heap.empty()) {
            // check top from min heap
            int min_val = min_heap.top();
            // check cnt for the val -> if > 0, choose it
            // otherwise, pop and check the next (continue)
            if (cnt_map[min_val] == 0) {
                min_heap.pop();
                continue;
            }
            
            cnt_map[min_val] -= 1;

            // once the initial is selected,
            // check from k to k + groupsize - 1 and assert all have cnt > 0
            for (int i = 1; i < groupSize; i++) {
                if (cnt_map[min_val + i] == 0) {
                    return false;
                }
                cnt_map[min_val + i] -= 1;
            }

        }

        return true;
    }
};
