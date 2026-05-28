class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        // mapping[i] = j meanings nums1[i] == nums2[j]

        // hash table for nums2 (num -> idx in nums2)
        // use queue to store duplicate
        unordered_map<int, queue<int>> nums2_idx_map;
        for (int i = 0; i < nums2.size(); i++) {
            nums2_idx_map[nums2[i]].push(i);
        }

        vector<int> mapping;
        for (int i = 0; i < nums1.size(); i++) {
            mapping.push_back(nums2_idx_map[nums1[i]].front());
            nums2_idx_map[nums1[i]].pop();
        }

        return mapping;

    }
};
