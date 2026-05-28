class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        // 1. using max heap -> O(nlogn)
        // 2. sort and loop back from the end -> O(nlogn)
        sort(nums.begin(), nums.end());
        int max_unique = -1;
        int tmp_max = -1;
        int tmp_max_cnt = 0;
        for (auto rit = nums.rbegin(); rit != nums.rend(); rit++) {
            if (*rit == tmp_max) {
                tmp_max_cnt += 1;
            } else {
                if (tmp_max_cnt == 1) {
                    max_unique = tmp_max;
                    break;
                } else {
                    tmp_max= *rit;
                    tmp_max_cnt = 1;
                }
            }
        }

        if (tmp_max_cnt == 1) { // handle the last one
            max_unique = tmp_max;
        }

        return max_unique;
    }
};
