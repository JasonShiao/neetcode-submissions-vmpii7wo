class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // Key:
        // ***Since there are "even" num of piles***,
        // what Alice can do is: 
        //    Pick (all odds) or (all evens) idx of piles
        //    So if Alice knows either sum(odds) or sum(evens) is larger
        //    she definitely could win if she want

        // First pick
        // Select 0 -> for even
        // Select piles.size() - 1 -> for odd
        // and then ....
        int sum_even = 0;
        int sum_odd = 0;
        for (int i = 0; i < piles.size(); i++) {
            if (i % 2) { // odd
                sum_odd += piles[i];
            } else { // even
                sum_even += piles[i];
            }
        }

        if (sum_odd > sum_even) {
            // Alice pick from last
        } else {
            // Alice pick from 0
        }

        return true;
    }
};