class Solution {
public:
    int rob(vector<int>& nums) {
        // Notice: it is NOT optimal to rob "every" house spaced by 2
        //         i.e. all even houses, all odd houses

        // tips: only two-step jump or three-step jump is possible
        // because couldn't be maximum if there are 3 consecutive houses not chosen
        
        // 0 | 1 | 2 | 3 | 4 | ....
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        // notice: the 3rd element in dp is the sum (trivial maximum)
        int dp[3] = {nums[0], nums[1], nums[0]+nums[2]};
        for (int i = 3; i < nums.size(); i++) {
            int temp = dp[2];
            // select next house, update
            dp[2] = nums[i] + max(dp[0], dp[1]);
            // update dp
            dp[0] = dp[1]; // 1st to zeroth
            dp[1] = temp; // old 2nd to 1st
        }

        return max({dp[0], dp[1], dp[2]});
    }
};
