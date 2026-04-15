class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; // smallest idx
        int right = nums.size() - 1; // largest idx

        // special case: out of bound
        if (target > nums[right] || target < nums[left]) {
            return -1;
        }

        while (right >= left) {
            // cut in half
            int half = (right + left) / 2;
            if (nums[half] == target) {
                return half;
            } else if (nums[half] < target) {
                // half - target - right
                left = half + 1;
            } else if (nums[half] > target) {
                right = half - 1;
            }
        }

        return -1;
    }
};
