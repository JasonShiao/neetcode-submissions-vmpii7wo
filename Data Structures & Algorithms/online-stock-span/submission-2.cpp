class StockSpanner {
    stack<pair<int, int>> price_span_stack;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        // Tricks: "compress" the price span
        //         A high price (with span) summarizes the previous low prices
        int span = 1; // including itself

        while (!price_span_stack.empty() && price >= price_span_stack.top().first) {
            span += price_span_stack.top().second;
            price_span_stack.pop();
        }

        price_span_stack.push(make_pair(price, span));

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */