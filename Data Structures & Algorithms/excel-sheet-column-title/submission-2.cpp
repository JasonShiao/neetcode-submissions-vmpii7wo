class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s;
        // like changing the base for representation of number
        while (columnNumber > 0) {
            s.push_back(((columnNumber - 1) % 26) + 'A');
            columnNumber = (columnNumber - 1) / 26;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};