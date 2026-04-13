class Solution {
public:
    int jump(vector<int>& nums) {
        // steps required to reach 
        // all pos between last frontier to the new frontier are the same
        vector<int> min_steps(nums.size(), -1);
        min_steps[0] = 0;
        int reachable = 0;
        for (int cur = 0; cur < nums.size(); cur++) {
            // already exclude the non-reachable case
            // if (cur > reachable) {
            //     ...
            // }

            if (cur + nums[cur] > reachable) {
                // new reachable frontier
                int new_reachable = cur + nums[cur];
                for (int i = reachable + 1; i <= new_reachable; i++) {
                    min_steps[i] = min_steps[cur] + 1;
                }
                reachable = new_reachable;
            }

            // when reachable, return
            // min steps required for the last pos
            if (reachable >= (nums.size() - 1)) {
                return min_steps[nums.size() - 1];
            }

        }
    }
};
