class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // total angry is fixed
        // problem: maximize the effect of grumpy reduction technique

        // maximize the window sum
        int max_window = 0;
        int total_satisfied = 0; // total without the technique
        int window = 0; // num of customer from unsatisfied to satisfied
        for (int i = 0; i < customers.size(); i++) {
            if (i < minutes) {
                window += customers[i] * grumpy[i];
            } else {
                window += customers[i] * grumpy[i];
                window -= customers[i - minutes] * grumpy[i - minutes];
            }
            max_window = max(window, max_window);

            total_satisfied += customers[i] * (1 - grumpy[i]); 
        }


        return total_satisfied + max_window;
    }
};