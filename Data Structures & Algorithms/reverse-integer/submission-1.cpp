class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int digit = 0;
        while (x != 0) {
            digit = x % 10;
            x /= 10;

            // Keypoint: how to check overflow!!
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7))
                return 0;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit < -8))
                return 0;
            
            res = res * 10 + digit;
        }
        return res;
    }
};
