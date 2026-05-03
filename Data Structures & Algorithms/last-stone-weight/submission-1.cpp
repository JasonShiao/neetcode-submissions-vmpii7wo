class Solution {
public:
    int popOne(vector<int>& heap) {
        int ret = heap[1];
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        int curr = 1;
        while (curr * 2 < heap.size()) {
            int left = curr * 2;
            int right = curr * 2 + 1;
            int larger_idx;
            if (right < heap.size()) {
                larger_idx = heap[left] > heap[right] ? left : right;
            } else {
                larger_idx = left;
            }
            if (heap[larger_idx] > heap[curr]) {
                int temp = heap[larger_idx];
                heap[larger_idx] = heap[curr];
                heap[curr] = temp;
                curr = larger_idx;
            } else {
                break;
            }
        }

        return ret;
    }

    void addOne(vector<int>& heap, int val) {
        heap.push_back(val);

        int curr = heap.size() - 1;
        while (curr > 1) {
            int parent = curr / 2;
            if (heap[curr] > heap[parent]) {
                int temp = heap[parent];
                heap[parent] = heap[curr];
                heap[curr] = temp;
                curr = parent;
            } else {
                break;
            }
        }
    }

    int lastStoneWeight(vector<int>& stones) {
        // 1. heapify (duplicate the first stone for 1-indexed)
        stones.push_back(stones[0]);
        int cur = stones.size() - 1; // point to the last one
        cur = cur / 2;
        while (cur > 0) {
            // percolate down
            int i = cur;
            while (i * 2 < stones.size()) {
                int left = i * 2;
                int right = i * 2 + 1;
                int larger_idx;
                if (right < stones.size()) {
                    larger_idx = stones[left] > stones[right] ? left : right;
                } else {
                    larger_idx = left;
                }
                if (stones[larger_idx] > stones[i]) {
                    int temp = stones[larger_idx];
                    stones[larger_idx] = stones[i];
                    stones[i] = temp;

                    i = larger_idx;
                } else {
                    break;
                }
            }
            cur -= 1;
        }

        
        while (stones.size() > 2) {
            // 2. pop 2 and (add 1 if not equal)
            int heaviest = popOne(stones);
            int second_heaviest = popOne(stones);
            if (heaviest == second_heaviest) {
                // don't add
            } else {
                // add back (heaviest - second_heaviest)
                addOne(stones, heaviest - second_heaviest);
            }
        }

        if (stones.size() == 1) {
            return 0;
        } else {
            return stones[1];
        }
    }
};
