class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Dynamic Programming from back

        unordered_map<int, int> lis; // the longest subsequence that INCLUDES i
        lis[nums.size() - 1] = 1;
        int maxLIS = 1;
        // O(n^2)
        for (int i = nums.size() - 2; i >= 0; i--) {
            int curLIS = 1;
            // iterate through each of latter lis
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] < nums[j]) {
                    // This indicates the nums[i] 
                    // can be appended to the front of 
                    // subsequence that starts with j
                    curLIS = max(curLIS, lis[j] + 1);
                }
            }
            // update the result
            lis[i] = curLIS;
            // update maxLIS on the fly
            if (maxLIS < curLIS) {
                maxLIS = curLIS;
            }
        }

        return maxLIS;
    }
};
