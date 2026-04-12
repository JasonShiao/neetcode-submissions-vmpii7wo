class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1; // plus one
        for (auto rit = digits.rbegin(); rit != digits.rend(); rit++) {
            // update current digit
            result.push_back((*rit + carry) % 10);
            // update carry for the next digit
            if (*rit + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
        }
        // the remaining one if carry not 0
        if (carry) {
            result.push_back(carry);
        }

        vector<int> reversed(result.rbegin(), result.rend());
        return reversed;
    }
};
