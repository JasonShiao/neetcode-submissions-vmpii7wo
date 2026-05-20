class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Note: Can't find # of rotation first, since it takes O(n) > O(logn) 
        int left_idx = 0;
        int right_idx = nums.size() - 1;
        while (left_idx <= right_idx) {
            int half_idx = (left_idx + right_idx) / 2;

            if (nums[half_idx] == target) {
                return half_idx;
            }

            // !!!!!Tricky condition!!!!
            // Left half is sorted
            if (nums[left_idx] <= nums[half_idx]) {
                if (nums[left_idx] <= target && target < nums[half_idx]) {
                    right_idx = half_idx - 1;
                } else {
                    left_idx = half_idx + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[half_idx] < target && target <= nums[right_idx]) {
                    left_idx = half_idx + 1;
                } else {
                    right_idx = half_idx - 1;
                }
            }

        }

        return -1;
    }
};
