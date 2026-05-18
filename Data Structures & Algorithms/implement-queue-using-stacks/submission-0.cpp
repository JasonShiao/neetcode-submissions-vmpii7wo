class MyQueue {
private:
    stack<int> in_stack_;
    stack<int> out_stack_;
public:
    MyQueue() {
        // Tips 1: two stacks: in_stack & outstack
        // Tips 2: lazy loading the out_stack
        // push
        // put the new one to in_stack

        // pop
        // if out_stack is empty
        //  move "all" items from in_stack to out_stack
        // otherwise, pop from out_stack directly

    }
    
    void push(int x) {
        in_stack_.push(x);
    }
    
    int pop() {
        if (out_stack_.empty()) {
            // move all from in_stack to out_stack 
            while (!in_stack_.empty()) {
                out_stack_.push(in_stack_.top());
                in_stack_.pop();
            }
        }

        int res = out_stack_.top();
        out_stack_.pop();
        return res;
    }
    
    int peek() {
        if (out_stack_.empty()) {
            // move all from in_stack to out_stack 
            while (!in_stack_.empty()) {
                out_stack_.push(in_stack_.top());
                in_stack_.pop();
            }
        }

        return out_stack_.top();
    }
    
    bool empty() {
        if (in_stack_.empty() && out_stack_.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */