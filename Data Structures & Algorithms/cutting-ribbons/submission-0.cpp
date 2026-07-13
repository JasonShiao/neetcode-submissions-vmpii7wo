class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        // guess x -> validate

        auto is_valid = [&](int guess) {
            int accum = 0;
            for (auto ribbon: ribbons) {
                accum += ribbon / guess;
                if (accum >= k) {
                    return true;
                }
            }

            return false;
        };

        // binary search
        // 1. determine range
        int l = 1;
        int r = 0; // use max length of ribbon
        for (auto ribbon: ribbons) {
            if (ribbon > r) {
                r = ribbon;
            }
        }
        // 2.
        int res = 0; // if impossible, return 0
        while (l <= r) {
            int m = (l + r) / 2;
            if (is_valid(m)) {
                res = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        return res;
    }
};
