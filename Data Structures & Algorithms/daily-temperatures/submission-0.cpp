class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(), 0);
        stack<tuple<int, int>> idx_val_stack;

        for (int i = 0; i < temperatures.size(); i++) {
            if (idx_val_stack.size() == 0) {
                idx_val_stack.push(make_tuple(i, temperatures[i]));
                continue;
            } else {
                while (idx_val_stack.size() && 
                        temperatures[i] > get<1>(idx_val_stack.top())) {
                    // # days = i - item_idx
                    results[get<0>(idx_val_stack.top())] = i - get<0>(idx_val_stack.top());
                    idx_val_stack.pop();
                }
                idx_val_stack.push(make_tuple(i, temperatures[i]));
            }
        }

        // Note: the remaining in the stack -> keep 0

        return results;
    }
};
