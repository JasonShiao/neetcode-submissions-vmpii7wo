class Solution {
public:
    // return false if a loop is detected
    bool dfs(int i, int prev, unordered_set<int>& visited,
            unordered_map<int, unordered_set<int>> adj) {
        // a loop is detected
        if (visited.find(i) != visited.end()) {
            return false;
        }

        visited.insert(i);
        
        for (auto neigh: adj[i]) {
            if (neigh == prev) {
                continue; // skip, prevent immediate backward
            }
            if (!dfs(neigh, i, visited, adj)) {
                return false;
            }
        }

        return true;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // DFS & visited & a "prev" arg to prevent going backward

        // Build the adj list for graph
        unordered_map<int, unordered_set<int>> adj;
        for (auto edge: edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        unordered_set<int> visited;
        return dfs(0, -1, visited, adj) && visited.size() == n;
    }
};
