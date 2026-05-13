class CountSquares {
private:
    // Note: the ordered map lookup is O(log n)
    //       but this is more convenient than unordered_map since it can
    //       directly use pair as key
    //       for unordered_map, we should define the pair hash operator

    map<pair<int, int>, int> cnt; 
public:
    CountSquares() {}

    void add(vector<int> point) {
        cnt[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        for (auto& [p, c] : cnt) {
            int x2 = p.first;
            int y2 = p.second;

            // side must be > 0
            if (x2 == x || y2 == y) {
                continue;
            }

            // check if the point can be the diagonal
            if (abs(x2 - x) != abs(y2 - y)) {
                continue;
            }

            ans += c * cnt[{x, y2}] * cnt[{x2, y}];
        }

        return ans;
    }
};