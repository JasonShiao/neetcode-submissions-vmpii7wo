class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> height_stack; // height, idx

        int res = 0;
        // rect area: (idx_2 - idx_1 + 1)*min_height
        for (int i = 0; i < heights.size(); i++) {
            if (height_stack.empty()) {
                height_stack.push({heights[i], i});
                continue;
            }

            if (heights[i] > height_stack.top().first) {
                height_stack.push({heights[i], i});
            } else if (heights[i] == height_stack.top().first) {
                // skip
            } else {
                // calc area for cropped rect and then pop
                int last_popped_idx = 0;
                while (!height_stack.empty() && heights[i] < height_stack.top().first) {
                    // calc area
                    int cand_area = height_stack.top().first * (i - height_stack.top().second);
                    if (cand_area > res) {
                        res = cand_area;
                    }
                    last_popped_idx = height_stack.top().second;
                    height_stack.pop();
                }
                height_stack.push({heights[i], last_popped_idx});
            }
        }

        // process remaining in the stack
        while (!height_stack.empty()) {
            auto p = height_stack.top();
            int cand_area = (heights.size() - p.second) * p.first;
            if (cand_area > res) {
                res = cand_area;
            }

            height_stack.pop();
        }

        return res;
    }
};
