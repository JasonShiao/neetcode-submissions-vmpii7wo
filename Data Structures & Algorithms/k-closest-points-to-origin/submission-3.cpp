float dist2Origin(vector<int>& point) {
    return point[0]*point[0] + point[1]*point[1];
    //return sqrt(point[0]*point[0] + point[1]*point[1]);
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Add point to heap until there are k elements in the heap,
        // After k, remove the max into the max heap, if the new one is smaller
        vector<vector<int>> max_heap; // store the k closest points

        // 0-indexed heap
        for (auto& point: points) {
            if (max_heap.size() < k) {
                // add
                max_heap.emplace_back(point);
                // percolate up
                int curr_idx = max_heap.size() - 1;
                while (curr_idx > 0) {
                    int parent_idx = (curr_idx - 1) / 2;
                    if (dist2Origin(max_heap[curr_idx]) > 
                        dist2Origin(max_heap[parent_idx])) {
                        vector<int> temp = max_heap[parent_idx];
                        max_heap[parent_idx] = max_heap[curr_idx];
                        max_heap[curr_idx] = temp;

                        curr_idx = parent_idx;
                    } else {
                        break;
                    }
                }
            } else { // kick out max if new is smaller
                if (dist2Origin(point) < dist2Origin(max_heap[0])) {
                    // replace and percolate down
                    max_heap[0] = point;
                    int curr_idx = 0;
                    while (curr_idx * 2 + 1 < k) { // do until no child
                        int left = curr_idx * 2 + 1;
                        int right = curr_idx * 2 + 2;
                        int larger_idx = left;
                        if (right < max_heap.size() && dist2Origin(max_heap[right]) > dist2Origin(max_heap[left])) {
                            larger_idx = right;
                        }

                        if (dist2Origin(max_heap[larger_idx]) > dist2Origin(max_heap[curr_idx])) {
                            vector<int> temp = max_heap[larger_idx];
                            max_heap[larger_idx] = max_heap[curr_idx];
                            max_heap[curr_idx] = temp;

                            curr_idx = larger_idx;
                        } else {
                            break;
                        }
                    }
                }
            }
        }

        // return the entire heap
        return max_heap;

    }
};
