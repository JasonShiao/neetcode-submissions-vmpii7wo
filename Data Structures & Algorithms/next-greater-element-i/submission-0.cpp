class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // build a map from nums2
        // find the first greater using stack
        unordered_map<int, int> lookup;
        stack<int> val_stack; // the stack is maintained in decreasing order
        for (auto num: nums2) {
            // check with stack and add to lookup
            while (!val_stack.empty() && val_stack.top() < num) {
                lookup[val_stack.top()] = num;
                val_stack.pop();
            }
            // push to stack
            val_stack.push(num);
        }

        // iterate through nums1
        vector<int> res;
        for (auto num: nums1) {
            if (lookup.find(num) == lookup.end()) {
                res.push_back(-1);
            } else {
                res.push_back(lookup[num]);
            }
        }
        return res;
    }
};