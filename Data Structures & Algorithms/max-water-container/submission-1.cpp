class Solution {
public:
    int maxArea(vector<int>& heights) {
        // start two pointers on the two edges (i.e. 0 & heights.size() - 1)
        int left = 0;
        int right = heights.size() - 1;
        int max_water = 0;

        while (left < right) {
            int h = min(heights[left], heights[right]);
            int width = right - left;
            max_water = max(max_water, h * width);

            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_water;
    }
};
