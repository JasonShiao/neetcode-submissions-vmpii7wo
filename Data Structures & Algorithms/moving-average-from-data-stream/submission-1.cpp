class MovingAverage {
private:
    int size_; // max window size
    queue<int> window; // window_size <= size_
    long long window_sum;
public:
    MovingAverage(int size) {
        size_ = size;
        window_sum = 0;
    }
    
    double next(int val) {
        if (window.size() == size_) {
            // pop one and add one
            window_sum -= window.front();
            window.pop();
            window_sum += val;
            window.push(val);
        } else {
            // add one
            window_sum += val;
            window.push(val);
        }

        return (double)window_sum / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
