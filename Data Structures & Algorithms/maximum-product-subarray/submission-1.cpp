class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Iterate from 1 to nums.size()
        // maintain min and max product of subarray that **includes num**

        int res = INT_MIN;

        int maxProd = 1;
        int minProd = 1;

        for (auto num: nums) {
            // to get max -> 3 cases
            int tmpMax = max(maxProd * num, minProd * num);
            tmpMax = max(tmpMax, num);
            // to get min -> 3 cases
            int tmpMin = min(maxProd * num, minProd * num);
            tmpMin = min(tmpMin, num);

            maxProd = tmpMax;
            minProd = tmpMin;

            res = max(res, maxProd);

            if (num == 0) {
                maxProd = 1;
                minProd = 1;
            }
        }

        return res;
    }
};
