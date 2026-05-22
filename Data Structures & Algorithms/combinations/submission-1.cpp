class Solution {
public:
    void backtrack(const int& n, int i, 
            int cnt, const int& k,
            vector<vector<int>>& res, 
            vector<int>& cur_combination) {
        if (cnt == k) { // complete a combination
            res.push_back(cur_combination);
            return;
        }
        if (i > n) {
            return;
        }

        // exclude i
        backtrack(n, i + 1, cnt, k, res, cur_combination);
        // include i
        cur_combination.push_back(i);
        backtrack(n, i + 1, cnt + 1, k, res, cur_combination);
        cur_combination.pop_back(); // recover for upper layer (parent node) -> backtracking

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur_combination;
        backtrack(n, 1, 0, k, res, cur_combination);
        
        return res;
    }
};