class Solution {
public:
    int check_time_req(int& k, vector<int>& piles) {
        int time_req = 0;
        for (int i = 0; i < piles.size(); i++) {
            int div = piles[i] / k;
            int r = piles[i] % k;
            time_req += (r > 0 ? div + 1 : div);
        }

        return time_req;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // max possible k = max of pile
        int k_max = *max_element(piles.begin(), piles.end());

        // special case is excluded 

        // binary search
        // time req for lowerbound of k (speed)
        int left_time_req = accumulate(piles.begin(), piles.end(), 0);
        if (h == left_time_req) {
            return 1;
        }
        // time req for upperbound of k (speed)
        int right_time_req = piles.size();
        int left = 1;
        int right = k_max;
        while (!((left_time_req == right_time_req) && (left_time_req <= h))) {
            int half = (left + right) / 2;

            // check guess
            int half_time_req = check_time_req(half, piles);

            // update or return
            // we want k as small as possible but satisfy (time <= h)
            if (half_time_req <= h) {
                right = half;
                right_time_req = half_time_req;
            } else if (half_time_req > h) {
                left = half + 1;
                left_time_req = check_time_req(left, piles);;
            }
        }

        return left;
    }

    
};
