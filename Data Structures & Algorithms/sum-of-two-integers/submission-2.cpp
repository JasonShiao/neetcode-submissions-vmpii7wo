class Solution {
public:
    int getSum(int a, int b) {
        // keep add the remaining carry (with shift)
        while (b != 0) {
            unsigned carry = (unsigned)(a & b) << 1;  // important
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
