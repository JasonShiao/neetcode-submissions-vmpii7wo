class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        int mid;
        while (l <= r) {
            mid = (l + r) / 2;

            // special handle!
            if (r - l <= 1) { // already try all
                if (target <= nums[l]) {
                    return l;
                } else if (target <= nums[r]) {
                    return r;
                } else {
                    return r+1; // special case -> exceed origin array
                }
            }

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            }

        }

        return -1;
    }
};