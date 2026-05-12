class Solution {
public:
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            l += 1;
            r -= 1;
        }
    }
    void rotate(vector<int>& nums, int k) {
        // Approach 1: in-place but brute-force O(nk): 
        //     keep bubble the last element to the first
        //     repeat for k times

        // !!!Approach 2: O(1) space and O(n) time
        //.  reverse whole, 
        //.  reverse first k, 
        //.  reverse the last n-k
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, (k % nums.size()) - 1);
        reverse(nums, k % nums.size(), nums.size() - 1);

    }
};