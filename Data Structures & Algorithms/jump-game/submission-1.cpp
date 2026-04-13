class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int cur = 0; cur < nums.size(); cur++) {
            // check current idx is reachable first
            if (cur > reachable) {
                return false;
            }

            // update reachable if necessary
            if (nums[cur] + cur > reachable) {
                reachable = nums[cur] + cur;
            }

            // check the final idx already reachable
            if (reachable >= (nums.size()-1)) {
                return true;
            }
        }

        return false;
    }
};
