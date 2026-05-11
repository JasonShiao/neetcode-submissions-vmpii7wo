class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r) {
        auto cur_1 = l;
        auto cur_2 = m + 1;
        vector<int> result;
        while ((cur_1 <= m) || (cur_2 <= r)) {
            if (cur_1 > m) { // select cur2 only
                result.push_back(nums[cur_2]);
                cur_2 += 1;
            } else if (cur_2 > r) { // select cur 1 only
                result.push_back(nums[cur_1]);
                cur_1 += 1;
            } else { // check cur1 and cur2
                if (nums[cur_1] <= nums[cur_2]) {
                    result.push_back(nums[cur_1]);
                    cur_1 += 1;
                } else {
                    result.push_back(nums[cur_2]);
                    cur_2 += 1;
                }
            }
        }
        // copy result to num
        for (size_t i = 0; i < result.size(); ++i) {
            nums[l+i] = result[i];
        }
    }
    void mergeSortArray(vector<int>& nums, int l, int r) {
        // [l, r]
        if (l == r) { // only one element
            return;
        }
        if (l == r-1) { // only two element
            if (nums[l] > nums[r]) { // swap two
                int temp = nums[r];
                nums[r] = nums[l];
                nums[l] = temp;
            }
            return;
        }
        // sort inside each of the two halves
        mergeSortArray(nums, l, (r + l) / 2);
        mergeSortArray(nums, (r + l) / 2 + 1, r);
        
        // merge two sorted halves (this would use extra space, not in-place!!)
        merge(nums, l, (r + l) / 2, r);

    }
    vector<int> sortArray(vector<int>& nums) {
        // merge sort
        mergeSortArray(nums, 0, nums.size() - 1);
        return nums;
    }
};