class Solution {
public:
    void search_connected(vector<bool> &visited,
                            vector<vector<int>>& isConnected,
                            int i) {
        int n = isConnected.size();

        // bfs
        deque<int> dq;
        dq.push_back(i);
        visited[i] = true;
        while (!dq.empty()) {
            auto p = dq.front();
            dq.pop_front();
            for (int j = 0; j < n; j++) {
                if (j == p) {
                    continue;
                }
                if (visited[j]) {
                    continue;
                }
                if (isConnected[p][j]) {
                    dq.push_back(j);
                    visited[j] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // i.e. total num of connected components

        int n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue;
            }

            search_connected(visited, isConnected, i);
            res += 1;
        }
        
        return res;
    }
};