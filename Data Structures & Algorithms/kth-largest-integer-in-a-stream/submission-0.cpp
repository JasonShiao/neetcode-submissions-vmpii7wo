class KthLargest {
private:
    int k_;
    vector<int> heap_;
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        heap_.push_back(0); // add a dummy

        // Note: min heap of k largest val instead of max heap!
        for (auto num: nums) {
            if (heap_.size() > k_) {
                // compare with min and replace if larger
                if (num > heap_[1]) {
                    heap_[1] = num;
                    // maintain min heap
                    int curr_idx = 1;
                    while (curr_idx < heap_.size()) {
                        if (curr_idx * 2 + 1 < heap_.size()) {
                            // both leaves exist
                            int left = curr_idx * 2;
                            int right = curr_idx * 2 + 1;
                            int smaller = left;

                            if (heap_[right] < heap_[left]) {
                                smaller = right;
                            }
                            if (heap_[curr_idx] > heap_[smaller]) {
                                int temp = heap_[smaller];
                                heap_[smaller] = heap_[curr_idx];
                                heap_[curr_idx] = temp;

                                curr_idx = smaller;
                            } else {
                                break;
                            }
                        } else if (curr_idx * 2 < heap_.size()) {
                            // left leaf exists
                            if (heap_[curr_idx] > heap_[curr_idx * 2]) {
                                int temp = heap_[curr_idx * 2];
                                heap_[curr_idx * 2] = heap_[curr_idx];
                                heap_[curr_idx] = temp;

                                curr_idx = curr_idx * 2;
                            } else {
                                break;
                            }
                        } else {
                            break;
                        }
                    }
                }
            } else {
                // add directly
                heap_.push_back(num);
                int curr_idx = heap_.size() - 1;
                while (curr_idx / 2 > 0) {
                    if (heap_[curr_idx] < heap_[curr_idx / 2]) {
                        int temp = heap_[curr_idx / 2];
                        heap_[curr_idx / 2] = heap_[curr_idx];
                        heap_[curr_idx] = temp;
                        curr_idx = curr_idx / 2;
                    } else {
                        break;
                    }
                }
            }
        }

    }
    
    int add(int val) {
        if (heap_.size() > k_) {
            // compare with min and replace if larger
            if (val > heap_[1]) {
                heap_[1] = val;
                // maintain min heap
                int curr_idx = 1;
                while (curr_idx < heap_.size()) {
                    if (curr_idx * 2 + 1 < heap_.size()) {
                        // both leaves exist
                        int left = curr_idx * 2;
                        int right = curr_idx * 2 + 1;
                        int smaller = left;

                        if (heap_[right] < heap_[left]) {
                            smaller = right;
                        }
                        if (heap_[curr_idx] > heap_[smaller]) {
                            int temp = heap_[smaller];
                            heap_[smaller] = heap_[curr_idx];
                            heap_[curr_idx] = temp;

                            curr_idx = smaller;
                        } else {
                            break;
                        }
                    } else if (curr_idx * 2 < heap_.size()) {
                        // left leaf exists
                        if (heap_[curr_idx] > heap_[curr_idx * 2]) {
                            int temp = heap_[curr_idx * 2];
                            heap_[curr_idx * 2] = heap_[curr_idx];
                            heap_[curr_idx] = temp;

                            curr_idx = curr_idx * 2;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
            }
        } else {
            // add directly
            heap_.push_back(val);
            int curr_idx = heap_.size() - 1;
            while (curr_idx / 2 > 0) {
                if (heap_[curr_idx] < heap_[curr_idx / 2]) {
                    int temp = heap_[curr_idx / 2];
                    heap_[curr_idx / 2] = heap_[curr_idx];
                    heap_[curr_idx] = temp;
                    curr_idx = curr_idx / 2;
                } else {
                    break;
                }
            }
        }

        return heap_[1];

    }
};
