class CountSquares {
private:
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

            if (x2 == x || y2 == y) {
                continue;
            }

            if (abs(x2 - x) != abs(y2 - y)) {
                continue;
            }

            ans += c * cnt[{x, y2}] * cnt[{x2, y}];
        }

        return ans;
    }
};