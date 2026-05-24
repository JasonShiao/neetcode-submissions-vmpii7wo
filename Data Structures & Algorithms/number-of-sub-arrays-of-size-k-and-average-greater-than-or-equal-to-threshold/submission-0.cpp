class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0;
        // don't use floating number -> easily cause troubles!
        int window_sum = 0;
        int sum_threshold = k * threshold;
        // initial window
        for (int i = 0; i < k; i++) {
            window_sum += arr[i];
        }
        if (window_sum >= sum_threshold) {
            cnt += 1;
        }

        for (int i = k; i < arr.size(); i++) {
            window_sum -= arr[i - k];
            window_sum += arr[i];
            if (window_sum >= sum_threshold) {
                cnt += 1;
            }
        }


        return cnt;
    }
};