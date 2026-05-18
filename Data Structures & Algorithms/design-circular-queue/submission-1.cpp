class MyCircularQueue { // i.e. ring buffer
private:
    vector<int> ringbuf;
    int k_;
    int size_; // Tips: use this to conveniently keep track of empty/full
    int head; // for add
    int tail; // for consume
public:
    MyCircularQueue(int k) {
        ringbuf.resize(k);
        k_ = k;
        size_ = 0;
        head = 0;
        tail = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            // full
            return false;
        }
        ringbuf[head] = value;
        size_ += 1;
        head = (head + 1) % k_;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) {
            // empty
            return false;
        }
        // update tail
        tail = (tail + 1) % k_;
        size_ -= 1;

        return true;
    }
    
    int Front() {
        if (isEmpty()) {
            // empty
            return -1;
        }
        return ringbuf[tail];
    }
    
    int Rear() {
        if (isEmpty()) {
            // empty
            return -1;
        }
        // one item before head
        return ringbuf[(head - 1 + k_) % k_];
    }
    
    bool isEmpty() {
        if (size_ == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    bool isFull() {
        if (size_ == k_) {
            // full
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */