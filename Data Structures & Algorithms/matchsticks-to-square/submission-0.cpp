class Solution {
public:
    bool backtracking(int i, vector<int>& side, vector<int>& matchsticks,
        const int side_len) {
        if (i == matchsticks.size()) {
            return true;
        }

        for (int j = 0; j < 4; j++) {
            if (side[j] + matchsticks[i] <= side_len) {
                // valid, keep dive deep
                side[j] += matchsticks[i];
                if (backtracking(i+1, side, matchsticks, side_len)) {
                    return true;
                }
                // backtrack
                side[j] -= matchsticks[i];
            }
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int side_len = sum / 4;

        vector<int> side = {0, 0, 0, 0};
        if (sum % 4 != 0) {
            return false;
        }

        // backtracking
        return backtracking(0, side, matchsticks, side_len);
    }
};