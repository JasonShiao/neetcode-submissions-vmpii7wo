class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> student_cnt{0, 0};
        for (auto& s: students) {
            student_cnt[s] += 1;
        }

        for (auto& sand: sandwiches) {
            if (student_cnt[sand] == 0) {
                break;
            }
            student_cnt[sand] -= 1;
        }
        return student_cnt[0] + student_cnt[1];
    }
};