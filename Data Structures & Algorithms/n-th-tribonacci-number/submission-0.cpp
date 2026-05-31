class Solution {
public:
    int tribonacci(int n) {
        int tn[3] = {0, 1, 1};
        if (n <= 2) {
            return tn[n];
        }
        while (n > 2) {
            auto tmp = tn[0] + tn[1] + tn[2];
            tn[0] = tn[1];
            tn[1] = tn[2];
            tn[2] = tmp;
            n -= 1;
        }
        return tn[n];
    }
};