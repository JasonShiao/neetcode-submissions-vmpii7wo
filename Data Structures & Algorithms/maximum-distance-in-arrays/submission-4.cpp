class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // Get the largest 2 nums and the smallest 2 nums
        // if max and min are in the same array,
        //   pick max(2nd max - min, largest - 2nd min)
        
        // Thus, only 3 cases in total (and two of them can be merged)
        
        int max_idx = arrays[0][arrays[0].size() - 1] >= arrays[1][arrays[1].size() - 1] ? 0 : 1;
        int max_2nd_idx = 1 - max_idx;
        int min_idx = arrays[0][0] <= arrays[1][0] ? 0 : 1;
        int min_2nd_idx = 1 - min_idx;

        for (int i = 2; i < arrays.size(); i++) {
            if (arrays[i].back() >= arrays[max_idx].back()) {
                max_2nd_idx = max_idx;
                max_idx = i;
            } else if (arrays[i].back() >= arrays[max_2nd_idx].back()) {
                max_2nd_idx = i;
            }

            if (arrays[i][0] <= arrays[min_idx][0]) {
                min_2nd_idx = min_idx;
                min_idx = i;
            } else if (arrays[i][0] <= arrays[min_2nd_idx][0]) {
                min_2nd_idx = i;
            }

        }

        if (max_idx != min_idx) {
            return arrays[max_idx].back() - arrays[min_idx][0];
        } else {
            return max(arrays[max_2nd_idx].back() - arrays[min_idx][0],
                    arrays[max_idx].back() - arrays[min_2nd_idx][0]);
        }


    }
};
