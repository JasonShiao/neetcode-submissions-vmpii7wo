class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    string gcdOfStrings(string str1, string str2) {
       if (str1 + str2 != str2 + str1) {
            return "";
        }

        int len = gcd(str1.size(), str2.size());

        return str1.substr(0, len); 
    }
};