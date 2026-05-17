class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int last_val = -101;
        int slow_ptr = 0;
        for (int fast_ptr = 0; fast_ptr < nums.size(); fast_ptr++) {
            if (nums[fast_ptr] != last_val) {
                // update last_val
                last_val = nums[fast_ptr];
                nums[slow_ptr] = nums[fast_ptr];
                slow_ptr += 1;
            } else {
                // do nothing
            }
        }

        return slow_ptr;
    }
};