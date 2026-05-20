class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // binary search
        // for each trial, test the required days

        // notice the cand must > max(weights)

        // key: determine the upperbound for binary search
        // intuitive: sum(weights)
        int l = 0; // at least the max(weights)
        int r = 0; // upperbound: sum(weights)
        for (auto w: weights) {
            r += w;
            if (w > l) { 
                l = w;
            }
        }

        int cand_capacity;
        while (l <= r) {
            int mid = (l + r) / 2;
            // calculate required days
            int days_req = 0;
            int day_weight_cum = 0;
            for (auto w: weights) {
                if (day_weight_cum + w > mid) {
                    // cut
                    days_req += 1;
                    day_weight_cum = w;
                } else {
                    day_weight_cum += w;
                }
            }
            if (day_weight_cum > 0) {
                days_req += 1;
            }
            // check condition
            if (days_req > days) {
                l = mid + 1;
            } else if (days_req < days) {
                r = mid - 1;
                cand_capacity = mid;
            } else { // find "least" capacity
                r = mid - 1;
                cand_capacity = mid;
            }
        }

        return cand_capacity;

    }
};