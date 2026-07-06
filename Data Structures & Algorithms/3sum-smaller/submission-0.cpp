class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // Brute force: O(n^3), i.e. go through all P(n, 3) triplets

        // Similar to 3Sum
        // 1. sort first
        sort(nums.begin(), nums.end());

        // 2. use two pointers approach
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            // i is the idx of smallest element
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] < target) {
                    // Update cnt with trick:
                    //   fast forward all k with smaller sum
                    cnt += (k - j);
                    // inc j will make the sum larger
                    j += 1;
                    // keeps k
                } else {
                    // move right ptr only
                    k -= 1;
                }
            }

        }

        return cnt;
    }
};
