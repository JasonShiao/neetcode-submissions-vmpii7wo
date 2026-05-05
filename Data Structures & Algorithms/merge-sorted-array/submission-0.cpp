class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int cur1 = 0;
        int cur2 = 0;
        while (cur1 < m || cur2 < n) {
            if (cur1 == m) {
                result.emplace_back(nums2[cur2]);
                cur2++;
            } else if (cur2 == n) {
                result.emplace_back(nums1[cur1]);
                cur1++;
            } else {
                if (nums1[cur1] <= nums2[cur2]) {
                    result.emplace_back(nums1[cur1]);
                    cur1++;
                } else {
                    result.emplace_back(nums2[cur2]);
                    cur2++;
                }
            }
        }

        copy(result.begin(), result.end(), nums1.begin());
    }
};