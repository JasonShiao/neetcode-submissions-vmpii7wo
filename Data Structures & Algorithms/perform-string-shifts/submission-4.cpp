class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int total_shift = 0;
        for (auto sh: shift) {
            if (sh[0] == 0) {
                total_shift -= sh[1];
            } else {
                total_shift += sh[1];
            }
        }

        int n = s.length();
        total_shift %= n;
        if (total_shift < 0) { // make the code cleaner -> unify left and right shift
            total_shift += n;
        }

        string res;
        // right shift
        for (int i = n - total_shift; i < n; i++) {
            res += s[i];
        }
        for (int i = 0; i < n - total_shift; i++) {
            res += s[i];
        }

        return res;
        //return s.substr(n - total_shift) + s.substr(0, n - total_shift);
    }
};
