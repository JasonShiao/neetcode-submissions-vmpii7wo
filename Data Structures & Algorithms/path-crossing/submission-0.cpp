class Solution {
public:
    bool isPathCrossing(string path) {
        // Don't use a grid for visited as the path can be 10000 in length

        // Option: can use an int hash to represent pair since it won't exceed
        //           10^9
        // maintain a visited node set
        unordered_set<int> visited;
        // hash: row*10001 + col
        int row = 0;
        int col = 0;
        visited.insert(0);
        for (auto dir: path) {
            if (dir == 'N') {
                row += 1;
            } else if (dir == 'S') {
                row -= 1;
            } else if (dir == 'W') {
                col += 1;
            } else if (dir == 'E') {
                col -= 1;
            }
            int hash = row * 10001 + col;
            if (visited.find(hash) != visited.end()) {
                return true;
            }
            visited.insert(hash);
        }

        return false;
    }
};