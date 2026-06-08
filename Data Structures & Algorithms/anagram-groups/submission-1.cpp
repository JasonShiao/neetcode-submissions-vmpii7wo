class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // key for the hash map:
        // "xx,xx,xx,xx,xx...." : 26 values with ',' as del
        unordered_map<string, vector<string>> group_map;

        // compute hash key and append to corresponding group by mapping
        for (auto s: strs) {
            vector<int> cnt(26, 0);
            for (auto c: s) {
                cnt[c - 'a'] += 1;
            }
            // concat cnt values
            string k = "";
            for (auto val: cnt) {
                k += "," + to_string(val);
            }
            // map key to group and append s
            group_map[k].push_back(s);
        }

        // construct the result
        vector<vector<string>> res;

        for (auto [key, subset]: group_map) {
            res.push_back(subset);
        }

        return res;
    }
};
