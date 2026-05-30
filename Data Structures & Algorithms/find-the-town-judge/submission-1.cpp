class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // build a trust map to set
        unordered_map<int, unordered_set<int>> trust_set;
        // build a trusted map to set
        unordered_map<int, unordered_set<int>> trusted_set;

        for (auto t: trust) {
            trust_set[t[0]].insert(t[1]);
            trusted_set[t[1]].insert(t[0]);
        }

        for (int i = 0; i <= n; i++) {
            if (trust_set[i].size() == 0 &&
                trusted_set[i].size() == (n-1)) {
                return i;
            }
        }

        return -1;

    }
};