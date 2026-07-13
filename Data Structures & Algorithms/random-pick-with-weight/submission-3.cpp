class Solution {
private:
    vector<int> wheel;
    uniform_int_distribution<int> distrib;
    std::mt19937 gen;
public:
    Solution(vector<int>& w) {
        // Roulette wheel with prefix sum
        int cum_sum = 0;
        for (int i = 0; i < w.size(); i++) {
            cum_sum += w[i];
            wheel.push_back(cum_sum);
        }

        gen = mt19937(random_device{}());
        distrib = uniform_int_distribution<int>(1, cum_sum);
    }
    
    int pickIndex() {
        // binary search for index
        // non-zero values inside (w[i-1], w[i]] -> select i
        // val = 0 -> i = 0
        int l = 0;
        int r = wheel.size() - 1;

        int rand = distrib(gen);
        while (l <= r) {
            int m = (l + r) / 2;
            if (m > 0 && rand <= wheel[m] && rand > wheel[m - 1]) {
                return m;
            } else if (rand > wheel[m]) {
                // search right
                l = m + 1;
            } else {
                // smaller than both
                r = m - 1;
            }
        }

        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */