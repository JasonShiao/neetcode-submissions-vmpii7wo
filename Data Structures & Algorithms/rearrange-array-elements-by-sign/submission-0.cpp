class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos;
        queue<int> neg;
        for (const auto& num: nums) {
            if (num > 0) {
                pos.push(num);
            } else {
                neg.push(num);
            }
        }

        vector<int> res;
        while (!pos.empty()) {
            res.push_back(pos.front());
            res.push_back(neg.front());
            pos.pop();
            neg.pop();
        }

        return res;
    }
};