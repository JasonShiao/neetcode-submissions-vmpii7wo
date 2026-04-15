class Solution {
public:
    int findMin(vector<int> &nums) {
        
        // high - low - mid: update right
        // low - mid - high: update right
        // mid - high - low: update left

        // minimum is always between low and high
        int left_idx = 0;
        int right_idx = nums.size() - 1;
        while (left_idx < (right_idx -1 )) {
            int half = (right_idx + left_idx) / 2;

            if (nums[left_idx] > nums[right_idx] && nums[right_idx] > nums[half]) {
                right_idx = half;
            } else if (nums[right_idx] > nums[half] && nums[half] > nums[left_idx]) {
                right_idx = half;
            } else if (nums[right_idx] < nums[left_idx] && nums[half] > nums[left_idx]) {
                left_idx = half;
            } else {
                // not possible
                return -1;
            }
        }

        return min({nums[left_idx],nums[right_idx]});
    }
};
