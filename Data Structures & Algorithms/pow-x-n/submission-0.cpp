class Solution {
public:
    double myPow(double x, int n) {
        int abs_n = n >= 0 ? n : -n;
        // special case:
        if (n == 0) {
            return 1;
        }

        double result = 1; // Notice: not 0!
        // keep multiply
        while (abs_n > 0) {
            result *= x;
            abs_n -= 1;
        }

        if (n < 0) {
            result = 1 / result;
        }

        return result;

    }
};
