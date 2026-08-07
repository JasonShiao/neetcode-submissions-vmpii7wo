class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        // Given map from child -> parent

        // 1. build the adj list from paretn -> child
        unordered_map<int, vector<int>> adj_list; // use ID instead of idx
        for (int i = 0; i < pid.size(); i++) {
            adj_list[ppid[i]].push_back(pid[i]);
        }

        // 2. start from the kill id
        vector<int> res;
        deque<int> dq;
        dq.push_back(kill);
        while (!dq.empty()) {
            auto p = dq.front();
            dq.pop_front();

            res.push_back(p);

            // enqueue neighbors
            for (auto neigh: adj_list[p]) {
                dq.push_back(neigh);
            }
        }

        return res;
    }
};
