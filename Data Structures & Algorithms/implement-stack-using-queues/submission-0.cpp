class MyStack {
private:
    deque<int> reversed_q[2];
    int cur = 0; // point to the current queue
public:
    MyStack() {
        // Constrain:
        //   Can only use push_back(), pop_front(), and front() of deque
    }
    
    void push(int x) {
        // Tips:
        // switch between two queues,
        // add the new item into another queue
        // pop all the itmes in the current queue and push to another queue
        // -> this makes the last item the first in queue (reversed order)
        int new_cur = (cur + 1) % 2;
        reversed_q[new_cur].push_back(x);
        while (reversed_q[cur].size()) {
            reversed_q[new_cur].push_back(reversed_q[cur].front());
            reversed_q[cur].pop_front();
        }
        cur = new_cur;
    }
    
    int pop() {
        // pop the last added = the front in the (reversed) queue
        int res = reversed_q[cur].front();
        reversed_q[cur].pop_front();
        return res;
    }
    
    int top() {
        // get the last added -> the front in the reversed queue
        return reversed_q[cur].front();
    }
    
    bool empty() {
        return reversed_q[cur].size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */