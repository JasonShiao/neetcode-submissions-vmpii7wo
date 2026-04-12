class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> results(n+1, 0);
        for (int num = 0; num <= n; num++) {
            int one_cnt = 0;
            int idx = 0;
            while (num >= (1 << idx)) {
                if (num & (1 << idx)) {
                    one_cnt += 1;
                }
                idx += 1;
            }
            results[num] = one_cnt;
        }

        return results;
    }
};
