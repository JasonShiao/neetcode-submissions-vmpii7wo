/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lower_bound = 1;
        int higher_bound = n;

        while (lower_bound <= higher_bound) {
            int half = (lower_bound + higher_bound) / 2;
            
            int guess_result = guess(half);
            if (guess_result < 0) {
                // half > num -> update right
                higher_bound = half - 1;
            } else if (guess_result > 0) {
                lower_bound = half + 1;
            } else {
                return half;
            }
        }

        return lower_bound;

    }
};