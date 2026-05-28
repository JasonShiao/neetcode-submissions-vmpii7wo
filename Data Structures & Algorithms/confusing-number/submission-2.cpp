class Solution {
public:
    bool confusingNumber(int n) {
        // extract each digit and check if it is valid to rotate
        // even it is valid -> still have to check if it is different
        int rotate_result = 0;
        int n_copy = n;
        while (n > 0) {
            int digit = n % 10;
            if (digit == 2 || digit == 3 || digit == 4 || digit == 5 || digit == 7) {
                return false;
            } else {
                rotate_result *= 10;
                switch (digit) {
                    case 0: 
                        rotate_result += 0;
                        break;
                    case 1: 
                        rotate_result += 1;
                        break;
                    case 6: 
                        rotate_result += 9;
                        break;
                    case 8: 
                        rotate_result += 8;
                        break;
                    case 9: 
                        rotate_result += 6;
                        break;
                }
            }

            n /= 10;
        }

        if (rotate_result == n_copy) {
            return false;
        }

        return true;
    }
};
