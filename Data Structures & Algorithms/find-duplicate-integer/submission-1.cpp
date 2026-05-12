class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Approach 1: O(n) in both space and time
        // vector<bool> lookup(nums.size(), false);
        // for (auto& num: nums) {
        //     if (lookup[num]) {
        //         return num;
        //     } else {
        //         lookup[num] = true;
        //     }
        // }

        // O(1) extra space using Floyd Cycle Detection
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        slow = nums[0];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    
    }
};
