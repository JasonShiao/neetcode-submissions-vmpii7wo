class NumArray {
private:
    vector<int> prefix_sum_;
public:
    NumArray(vector<int>& nums) {
        int current_sum = 0;
        for (auto num: nums) {
            current_sum += num;
            prefix_sum_.push_back(current_sum);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return prefix_sum_[right];
        }
        return prefix_sum_[right] - prefix_sum_[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */