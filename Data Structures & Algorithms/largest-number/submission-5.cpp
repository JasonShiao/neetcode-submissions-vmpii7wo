class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // **special case**:
        bool non_zero = false;
        vector<string> nums_str;
        for (auto num: nums) {
            if (num > 0) {
                non_zero = true;
            }
            nums_str.push_back(to_string(num));
        }
        if (!non_zero) {
            return "0";
        }

        std::sort(nums_str.begin(), nums_str.end(), 
            [](const string& digits_a, const string& digits_b) {
                int i = 0;
                char tmp_a = digits_a[0];
                char tmp_b = digits_a[0];
                // This logic is critical!!!
                while (i < (digits_a.length() + digits_b.length())) {
                    if (i < digits_a.length()) {
                        tmp_a = digits_a[i];
                    } else {
                        tmp_a = digits_b[i - digits_a.length()];
                    }
                    if (i < digits_b.length()) {
                        tmp_b = digits_b[i];
                    } else {
                        tmp_b = digits_a[i - digits_b.length()];
                    }
                    if (tmp_a < tmp_b) {
                        return false;
                    } else if (tmp_a > tmp_b) {
                        return true;
                    } else {
                        // tied -> keep going
                    }

                    i += 1;
                }

                return false; // Returns true if 'a' should come before 'b'
            }
        );

        string res;
        for (auto digits: nums_str) {
            res += digits;
        }

        return res;
    }
};