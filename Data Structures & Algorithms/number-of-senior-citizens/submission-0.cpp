class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (int i = 0; i < details.size(); i++) {
            int age = details[i][11] - '0';
            age *= 10;
            age += details[i][12] - '0';
            if (age > 60) {
                cnt += 1;
            }
        }

        return cnt;
    }
};