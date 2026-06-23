class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // target = total/2
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2) {
            return false;
        }

        unordered_set<int> possible_sum;
        possible_sum.insert(0); // this is critical
        for (auto num: nums) {
            unordered_set<int> new_possible_sum;
            for (auto t: possible_sum) {
                new_possible_sum.insert(t + num);
                new_possible_sum.insert(t);
            }
            possible_sum = new_possible_sum;
        }

        int target = total / 2;
        if (possible_sum.find(target) == possible_sum.end()) {
            return false;
        } else {
            return true;
        }

    }
};
