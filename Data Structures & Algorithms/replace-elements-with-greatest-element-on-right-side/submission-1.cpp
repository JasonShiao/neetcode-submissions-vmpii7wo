class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // brute force is O(n^2) -> not feasible
        vector<int> result;
        // iterate and maintain the max among [i, end]
        // Get max incrementally from back:
        //    max in [i, end] = max(arr[i], max in [i+1, end])
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