class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // Insight 1: can only determine after iterate the "entire" arr   
        unordered_map<string, int> s_cnt;
        for (auto s: arr) {
            s_cnt[s] += 1;
        }

        int curr_distinct_cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (s_cnt[arr[i]] == 1) {
                // distinct string
                curr_distinct_cnt += 1;
                if (curr_distinct_cnt == k) {
                    return arr[i];
                }
            } else {
                // non distrinct
            }
        }

        return "";
    }
};