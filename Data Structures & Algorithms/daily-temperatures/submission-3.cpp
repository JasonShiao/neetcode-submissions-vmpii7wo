class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> results(temperatures.size(), 0);
        stack<tuple<int, int>> idx_val_stack;

        // Key: maintain the stack so that
        //      lower layers in stack is always warmer than upper layers
        // i.e. monotonically decreasing stack

        // A higher temperature will clear some of the previous days (from the stack)
        // and the result for those popped days is assigned: (high_temp_idx - day_idx)
        // until it encounters a higher temperature in the stack!

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
