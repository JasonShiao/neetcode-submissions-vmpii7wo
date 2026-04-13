class MinStack {
public:
    stack<int> stack_internal;
    stack<int> stack_min;

    MinStack() {
    }
    
    void push(int val) {
        stack_internal.push(val);
        if (stack_min.size() == 0) {
            stack_min.push(val);
        } else {
            if (val < stack_min.top()) {
                stack_min.push(val);
            } else {
                stack_min.push(stack_min.top());
            }
        }
    }
    
    void pop() {
        stack_internal.pop();
        stack_min.pop();
    }
    
    int top() {
        return stack_internal.top();
    }
    
    int getMin() {
        return stack_min.top();
    }
};
