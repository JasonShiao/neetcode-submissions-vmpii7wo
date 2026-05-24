class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort first could result in a solution largely improve the performance
        sort(nums.begin(), nums.end());

        // for loop iterate from 0 to n
        //    reduce from 3 sum to 2 sum
        vector<vector<int>> res;
        for (int i = 0; i < (nums.size() - 2); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int target = -nums[i];
            // two pointer
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    // add the solution
                    res.push_back({nums[i], nums[l], nums[r]});
                    l += 1;
                    while (l < r && nums[l] == nums[l-1]) {
                        l += 1;
                    }
                    r -= 1;
                    while (l < r && nums[r] == nums[r+1]) {
                        r -= 1;
                    }
                } else if (nums[l] + nums[r] > target) {
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }

        return res;

    }
};
