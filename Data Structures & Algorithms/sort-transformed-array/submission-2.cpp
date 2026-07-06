class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;

        // should do without resorting O(nlogn)
        // Can do with two pointers in O(n)


        auto f = [&](int x) {
            return a*x*x + b*x + c;
        };

        // handle special case: degrading to line
        if (a == 0) {
            for (auto num: nums) {
                res.push_back(f(num));
            }
            if (b < 0) {
                reverse(res.begin(), res.end());
            }
            return res;
        }

        // for a given parabola,
        // y is dec/inc when x approaces center
        // given a, b -> determine the focal of parabola (x = -b/2a)
        // check left/right ptr whose corresponding pos is farther to focal
        double focal = -(double)b / (2*a);

        int cur1 = 0;
        int cur2 = nums.size() - 1;
        while (cur1 <= cur2) {
            if (abs(nums[cur1] - focal) > abs(nums[cur2] - focal)) {
                res.push_back(f(nums[cur1]));
                cur1 += 1;
            } else {
                res.push_back(f(nums[cur2]));
                cur2 -= 1;
            }
        }

        // the result depends on signess of a
        if (a > 0) {
            reverse(res.begin(), res.end());
        }

        return res;
    }
};
