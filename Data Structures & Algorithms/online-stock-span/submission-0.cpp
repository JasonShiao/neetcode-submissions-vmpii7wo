class StockSpanner {
    stack<int> price_stack;
    stack<int> temp_stack;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        temp_stack.push(price);
        while (!price_stack.empty()) {
            if (price_stack.top() <= price) {
                temp_stack.push(price_stack.top());
                price_stack.pop();
            } else {
                break;
            }
        }
        int res = temp_stack.size();
        while (!temp_stack.empty()) {
            price_stack.push(temp_stack.top());
            temp_stack.pop();
        }

        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */