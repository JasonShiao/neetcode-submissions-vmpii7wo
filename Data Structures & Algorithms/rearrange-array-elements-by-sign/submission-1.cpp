class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Approach 1: not optimized
        // queue<int> pos;
        // queue<int> neg;
        // for (const auto& num: nums) {
        //     if (num > 0) {
        //         pos.push(num);
        //     } else {
        //         neg.push(num);
        //     }
        // }

        // vector<int> res;
        // while (!pos.empty()) {
        //     res.push_back(pos.front());
        //     res.push_back(neg.front());
        //     pos.pop();
        //     neg.pop();
        // }

        // Approach 2: use two pointers for pos and neg separately
        vector<int> res(nums.size(), 0);
        int pos_cursor = 0;
        int neg_cursor = 1;
        for (const auto& num: nums) {
            if (num > 0) {
                res[pos_cursor] = num;
                pos_cursor += 2;
            } else {
                res[neg_cursor] = num;
                neg_cursor += 2;
            }
        }

        return res;
    }
};