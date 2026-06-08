class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // generalized version of the Boyer-Moore Voting Algorithm
        // maintain two candidate and counter
        int cand1 = 0;
        int cand2 = 0;
        int cand1_cnt = 0;
        int cand2_cnt = 0;
        // Find the two most common cand (not guaranteed to > n/3)
        for (auto& num: nums) {
            if (num == cand1) {
                cand1_cnt += 1;
            } else if (num == cand2) {
                cand2_cnt += 1;
            } else if (cand1_cnt == 0) {
                cand1 = num;
                cand1_cnt = 1;
            } else if (cand2_cnt == 0) {
                cand2 = num;
                cand2_cnt = 1;
            } else {
                // dec both!!
                cand1_cnt -= 1;
                cand2_cnt -= 1;
            }
        }
        // Verify: check whether > n/3
        vector<int> res;
        cand1_cnt = 0;
        cand2_cnt = 0;
        for (auto& num: nums) {
            if (num == cand1) {
                cand1_cnt++;
            } else if (num == cand2) {
                cand2_cnt++;
            }
        }
        if (cand1_cnt > nums.size() / 3) {
            res.push_back(cand1);
        }
        if (cand2_cnt > nums.size() / 3) {
            res.push_back(cand2);
        }

        return res;
    }
};