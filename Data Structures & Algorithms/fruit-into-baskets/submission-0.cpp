class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Condition: num of types in the window <= 2

        int max_window = 0;
        unordered_map<int, int> window; // type count
        int l = 0; 
        for (int r = 0; r < fruits.size(); r++) {
            window[fruits[r]] += 1;
            while (l < r && window.size() > 2) {
                window[fruits[l]] -= 1;
                if (window[fruits[l]] == 0) {
                    window.erase(fruits[l]);
                }
                l++;
            }
            // valid window
            max_window = max(max_window, r - l + 1);
        }

        return max_window;
    }
};