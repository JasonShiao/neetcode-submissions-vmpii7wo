class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // a max in the middle -> pop all smaller values on the left
        // preserve smaller values on the right of max
        
        // X: when deque size == k -> need to pop front
        // O: use a left pointer -> to check whether we need to pop front
        vector<int> res;
        deque<int> dq; // store the index instead of value
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);
            if (l > dq.front()) {
                // pop front
                dq.pop_front();
            }
            if (r >= k - 1) {
                res.push_back(nums[dq.front()]);
                l++;
            }
        }

        return res;
    }
};
