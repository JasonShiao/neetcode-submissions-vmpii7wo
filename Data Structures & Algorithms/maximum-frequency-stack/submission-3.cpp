class FreqStack {
private:
    unordered_map<int, stack<int>> groups;
    int max_cnt = 0;
    unordered_map<int, int> val_cnt;
public:
    // Tips: Groups of val stack by cnt
    FreqStack() {
        max_cnt = 0;
    }
    
    void push(int val) {
        // O(1)
        val_cnt[val] += 1;
        // each "freq" of the val will push to a "separate" stack!!!
        groups[val_cnt[val]].push(val);
        if (val_cnt[val] > max_cnt) {
            max_cnt = val_cnt[val];
        }
    }
    
    int pop() {
        // O(1)
        // pop from max_cnt
        int top_val = groups[max_cnt].top();
        groups[max_cnt].pop();
        if (groups[max_cnt].empty()) {
            max_cnt -= 1;
        }
        // NOTICE: remember to decrement val_cnt
        val_cnt[top_val] -= 1;

        return top_val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */