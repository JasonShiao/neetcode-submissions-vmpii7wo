class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left > 0) {
            if (left == right) {
                // only the common prefix is remaining
                break;
            }
            shift += 1;
            left >>= 1;
            right >>= 1;
        }
        return left << shift;
    }
};