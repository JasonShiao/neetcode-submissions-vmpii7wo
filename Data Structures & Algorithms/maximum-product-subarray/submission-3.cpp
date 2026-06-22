class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Iterate from 1 to nums.size()
        // maintain min and max product of 
        // subarray of [0...num] that MUST INCLUDE num
        // (to be considered as a possible subarray with next idx)

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

            // Update in every iter
            res = max(res, maxProd);

            // Handle 0 here
            if (num == 0) {
                maxProd = 1;
                minProd = 1;
            }
        }

        return res;
    }
};
