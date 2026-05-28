class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> num_set;
        for (auto num: arr) {
            num_set.insert(num);
        }

        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (num_set.find(arr[i]+1) != num_set.end()) {
                cnt += 1;
            }
        }
        return cnt;
    }
};
