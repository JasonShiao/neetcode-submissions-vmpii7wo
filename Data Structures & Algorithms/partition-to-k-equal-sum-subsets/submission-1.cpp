class Solution {
public:
    bool backtracking(int i, vector<int>& nums, 
        vector<int>& bags, int k, int avg) {
        // i is the current decision index
        if (i == nums.size()) {
            return true;
        }

        for (int j = 0; j < k; j++) {
            if (bags[j] + nums[i] <= avg) {
                // dive deep
                bags[j] += nums[i];
                if (backtracking(i + 1, nums, bags, k, avg)) {
                    return true;
                }
                // backtrack (recover for upper layer)
                bags[j] -= nums[i];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int avg = sum / k;

        // impossible
        if (sum % k) {
            return false;
        }

        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> bags(k, 0);

        // backtracking
        return backtracking(0, nums, bags, k, avg);
    }
};