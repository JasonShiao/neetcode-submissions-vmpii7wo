class Solution {
public:
    string trimLeadingZeros(string s) {
        int i = 0;
        while (i < s.size() - 1 && s[i] == '0') {
            i++;
        }
        return s.substr(i);
    }
    string addBinary(string a, string b) {
        // sum of two binary = xor of the two '+' carry (i.e. and of the two << 1)
        // keep adding carry until no carry (carry = 0)
        string arg1 = a;
        string arg2 = b;
        do {
            auto rit_a = arg1.rbegin();
            auto rit_b = arg2.rbegin();
            string xor_two = "";
            string carry = "";
            while (rit_a != arg1.rend() || rit_b != arg2.rend()) {
                int bit_a = 0; // default
                int bit_b = 0; // default
                if (rit_a != arg1.rend()) {
                    bit_a = *rit_a - '0';
                    rit_a++;
                }
                if (rit_b != arg2.rend()) {
                    bit_b = *rit_b - '0';
                    rit_b++;
                }
                xor_two.push_back(((bit_a ^ bit_b) & 1) + '0'); // append to back (reverse once at end)
                carry.push_back(((bit_a & bit_b) & 0x1) + '0'); // append to back (reverse once at end)
            }
            // because we append in the reversed way above
            reverse(xor_two.begin(), xor_two.end());
            reverse(carry.begin(), carry.end());

            carry.push_back('0'); // shift left by 1 bit
            
            arg1 = trimLeadingZeros(xor_two);
            arg2 = trimLeadingZeros(carry);
        } while (arg2 != "0");

        return arg1;
    }
};