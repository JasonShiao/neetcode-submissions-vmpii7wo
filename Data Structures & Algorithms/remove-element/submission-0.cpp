class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cur = 0; // cursor to place the next non-val
        int non_val_cur = 0; // point to the first non-val which is not processed yet
        while (non_val_cur < nums.size()) {
            if (nums[non_val_cur] == val) {
                non_val_cur += 1;
                continue;
            }
            nums[cur] = nums[non_val_cur];
            cur += 1;
            non_val_cur += 1;
        }

        return cur;
    }
};