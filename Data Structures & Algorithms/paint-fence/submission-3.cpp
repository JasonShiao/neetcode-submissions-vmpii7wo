class Solution {
public:
    int numWays(int n, int k) {
        // for the initial 2 posts: k*k selections
        // from 3rd post, the prev selection matters

        // only need to maintain: at idx, 
        //     # possib for 2 consecutive same color 
        //          -> * (k-1) selections and update # of non consecutive same color
        //     # possib for non consecutive same color -> k selections
        //          -> * (k-1) selections and update # of non consecutive same color
        //          -> * 1 selection and update # of 2 consecutive same color

        if (n == 1) {
            return k;
        } else if (n == 2) {
            return k*k;
        }
        
        // for n >= 3

        // Handle edge case: k == 1!!!
        if (k == 1) {
            return 0;
        }

        int cnt_two_consec_same = k;
        int cnt_two_consec_diff = k*(k-1);
        for (int i = 3; i <= n; i++) {
            int next_cnt_two_consec_same = cnt_two_consec_diff;
            int next_cnt_two_consec_diff = (k-1)*(cnt_two_consec_same + cnt_two_consec_diff);

            cnt_two_consec_same = next_cnt_two_consec_same;
            cnt_two_consec_diff = next_cnt_two_consec_diff;
        }
        return cnt_two_consec_same + cnt_two_consec_diff;
    }
};
