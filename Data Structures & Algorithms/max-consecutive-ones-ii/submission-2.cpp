class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // pos of 3 consecutive 0's
        // Approach 1:
        // use two pointers
        // both will only move forward -> O(n)
        // There are many special cases must be carefully handled:
        // [0]
        // [1]
        // [0, 1, 1, 1] -> 
        // [1, 1, 1, 0] -> 
        // Normal case: in the middle -> prev + 1 + curr
        // ....
         // use prev and curr to store consecutive ones window
        // when encountering a zero, update
        // int res = 0;
        // int prev = 0;
        // int curr = 0;
        // for (auto num: nums) {
        //     if (num == 0) {
        //         res = max(res, prev + curr);
        //         prev = curr + 1; 
        //         curr = 0; 
        //     } else {
        //         curr += 1;
        //     }
        // }

        // if (curr > 0) {
        //     res = max(res, prev + curr);
        // }
        // However, two pointers approach is difficult to handle these cases!!!


        // Approach 2:
        // Instead, use a sliding window -> the largest window that contains at most one 1
        int l = 0;
        int zero_cnt = 0;
        int max_window = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                zero_cnt += 1;
                // handle invalid window
                if (zero_cnt > 1) { // move l ptr until a zero is removed
                    while (l < r && zero_cnt > 1) {
                        if (nums[l] == 0) {
                            zero_cnt -= 1;
                        }
                        l++;
                    }
                }
            }
            // a new valid window
            max_window = max(max_window, r - l + 1);
        }


        return max_window;

    }
};
