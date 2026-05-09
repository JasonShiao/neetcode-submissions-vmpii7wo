class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result;
        // start from the right
        // iterate and maintain the max among [i, end]
        int max_to_end = -1;
        for (auto rit = arr.rbegin(); rit != arr.rend(); rit++) {
            result.push_back(max_to_end);
            if (*rit > max_to_end) {
                max_to_end = *rit;
            }
        }
        // reverse to return
        reverse(result.begin(), result.end());
        return result;
    }
};