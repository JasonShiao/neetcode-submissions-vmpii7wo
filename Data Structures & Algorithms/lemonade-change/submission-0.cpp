class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> change_at_hand;
        change_at_hand[5] = 0;
        change_at_hand[10] = 0;
        change_at_hand[20] = 0;

        for (auto bill: bills) {
            int remaining_change = bill - 5;
            while (remaining_change > 0) {
                if (remaining_change >= 10) {
                    if (change_at_hand[10] > 0) {
                        change_at_hand[10] -= 1;
                        remaining_change -= 10;
                    } else if (change_at_hand[5] > 0) {
                        change_at_hand[5] -= 1;
                        remaining_change -= 5;
                    } else {
                        return false;
                    }
                } else if (remaining_change >= 5) {
                    if (change_at_hand[5] > 0) {
                        change_at_hand[5] -= 1;
                        remaining_change -= 5;
                    } else {
                        return false;
                    }
                }
            }
            change_at_hand[bill] += 1;
        }

        return true;
    }
};