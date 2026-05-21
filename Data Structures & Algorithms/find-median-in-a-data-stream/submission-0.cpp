class MedianFinder {
private:
    priority_queue<int> max_heap; // smaller half
    priority_queue<int, vector<int>, greater<int>> min_heap; // larger half
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // always add to max_heap first
        max_heap.push(num);

        // and then do housekeeping
        // 1. if max in max_heap > min in min_heap -> move
        if (!min_heap.empty()) {
            if (max_heap.top() > min_heap.top()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }

        // 2. if unbalanced (heap size differ by more than 1) -> move
        // WARNING: carefully handle condition for .size(),
        //          this is always unsigned!!!!
        if (max_heap.size() > min_heap.size() + 1) {
            // move from max heap to min heap
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size() + 1) {
            // move from min heap to max heap
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else {
            // do nothing
        }

    }
    
    double findMedian() {
        if (min_heap.size() == max_heap.size()) {
            return (min_heap.top() + max_heap.top()) / 2.0;
        } else if (min_heap.size() == (max_heap.size() + 1)) { 
            return min_heap.top();
        } else {
            return max_heap.top();
        }
    }
};
