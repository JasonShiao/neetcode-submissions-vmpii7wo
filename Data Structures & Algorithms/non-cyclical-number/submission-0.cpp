class Solution {
public:
    bool isHappy(int n) {
        int sum_digit_square = n;
        int res = 0;
        set<int> seen_set;
        seen_set.insert(sum_digit_square);

        while (true) {
            res = sum_digit_square;
            sum_digit_square = 0;
            while (res > 0) {
                int digit = (res % 10);
                sum_digit_square += digit * digit;
                res /= 10;
            }
            //cout << sum_digit_square << endl;

            if (sum_digit_square == 1) {
                return true;
            }

            if (seen_set.find(sum_digit_square) != seen_set.end()) {
                return false;
            } 
            seen_set.insert(sum_digit_square);
        }


    }
};
