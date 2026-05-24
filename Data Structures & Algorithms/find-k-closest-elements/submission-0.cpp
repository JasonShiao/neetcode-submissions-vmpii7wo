class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = 0;
        
        // initialize
        // find the pos where transition from < x to > x
        while (r < (arr.size()) && arr[r] < x) {
            r += 1;
        }
        l = r - 1;

        deque<int> window_q;
        while (window_q.size() < k) {
            if (r >= arr.size()) {
                window_q.push_front(arr[l]);
                l -= 1;
            } else if (l < 0) {
                window_q.push_back(arr[r]);
                r += 1;
            } else if ((arr[r] - x) < (x - arr[l])) {
                window_q.push_back(arr[r]);
                r += 1;
            } else if ((arr[r] - x) >= (x - arr[l])) {
                window_q.push_front(arr[l]);
                l -= 1;
            }
        }

        vector<int> window;
        while (!window_q.empty()) {
            window.push_back(window_q.front());
            window_q.pop_front();
        }

        return window;
    }
};