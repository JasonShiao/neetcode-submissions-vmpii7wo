class Solution {
public:
    long long minEnd(int n, int x) {
        // 1. num of zeros in x

        // any num AND with 0 will be 0
        // -> use a series continuous integers starting from 0
        //  for 0 (bit reset) in x
        // x = 1010
        // [0]:   1010
        // [1]:   1011
        // [2]:   1110
        long long fill = n-1;
        long long result = x;
        int index = 0;
        while (fill > 0) {
            if ((x & 1) == 0) {
                // fill
                result |= (fill & 1LL) << index;
                fill >>= 1;
            } else {

            }
            index += 1;
            x >>= 1;
        }

        return result;
        
    }
};