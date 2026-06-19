class Solution {
public:
    double bfs(string start, string end, 
        unordered_map<string, set<pair<string, double>>>& adj) {
        
        if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
            return -1;
        }

        queue<pair<string, double>> q; // {var, cummulative product result}
        unordered_set<string> visited;
        q.push({start, 1.0});
        visited.insert(start);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p.first == end) {
                return p.second;
            }

            for (auto e: adj[p.first]) {
                if (visited.find(e.first) == visited.end()) {
                    q.push({e.first, p.second * e.second});
                    // update visited here (before push to queue and process)!
                    visited.insert(e.first);
                }
            }
        }

        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // each equation and value create two edges: 
        //               (A, B) & (B, A) with inverse value
        // find the path starts with Ci and ends with Di
        // the product of path is the result

        // e.g. A / B * B / C * C / D = A / D

        // 1. create graph (adj list)
        unordered_map<string, set<pair<string, double>>> adj;
        // var -> {(nei_var, edge_weight), ...}
        for (int i = 0; i < equations.size(); i++) {
            // create edges for both direction
            adj[equations[i][0]].insert({equations[i][1], values[i]});
            adj[equations[i][1]].insert({equations[i][0], 1 / values[i]});
        }

        // 2. bfs for each query
        vector<double> res;
        for (auto query: queries) {
            res.push_back(bfs(query[0], query[1], adj));
        }

        return res;
    }
};