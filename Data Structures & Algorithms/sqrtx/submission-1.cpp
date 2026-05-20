class Solution {
public:
    int mySqrt(int x) {
        // binary search
        int l = 0;
        int r = x;

        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (1LL * mid * mid < x) {
                l = mid + 1;
            } else if (1LL * mid * mid > x) {
                r = mid - 1;
            } else {
                return mid;
            }
        }

        if (mid * mid > x) {
            return mid - 1;
        } else {
            return mid;
        }

        return -1;
    }
};