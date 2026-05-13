class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        // Big number multiply

        // Start from lowest digit
        // Each step:
        //   extract single digit from num2
        //   multiply all digits in num1 (handle carry)
        //.  shift n digit (depends on the position of digit in num2)
        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0); // "at most" n+m digit for result
        // tips: store and add the result for each digit
        for (int i = n - 1; i >=0; i--) {
            int digit_1 = num1[i] - '0';
            for (int j = m - 1; j >= 0; j--) {
                int digit_2 = num2[j] - '0';
                // multiply
                int prod = digit_1 * digit_2;
                // from the back (carry at most one digit forward)
                int curr_digit_idx = i + j + 1;
                int next_digit_idx = i + j;
                int sum = result[curr_digit_idx] + prod;
                result[next_digit_idx] += sum / 10; // Notice: += instead of =, this will accumulate multiple time !!!
                result[curr_digit_idx] = sum % 10;  // this is fixed after this iter
            }
        }

        // build the result
        string res;
        bool prefix_zero = true;
        for (int i = 0; i < result.size(); i++) {
            // find the first non-zero
            if (prefix_zero) {
                if (result[i] != 0) {
                    prefix_zero = false;
                    res.push_back(result[i]+'0');
                }
            } else {
                // after the first non-zero, append all the following
                res.push_back(result[i]+'0');
            }
        }
        
        return res;
    }
};
