class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int cur = 0; cur < nums.size(); cur++) {
            if (cur > reachable) {
                return false;
            }
            
            if (nums[cur] + cur > reachable) {
                reachable = nums[cur] + cur;
            }

            if (reachable >= (nums.size()-1)) {
                return true;
            }
        }

        return false;
    }
};
