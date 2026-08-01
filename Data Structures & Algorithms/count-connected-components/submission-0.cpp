class Solution {
public:
    void dfs(int i, unordered_map<int, vector<int>>& adj_list, 
        vector<bool>& visited) {
        // already mark visited before dfs for i

        // dfs neighbors
        for (auto neigh: adj_list[i]) {
            if (visited[neigh]) {
                continue; // skip
            }
            // mark visited
            visited[neigh] = true;
            dfs(neigh, adj_list, visited);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        // X: map each node to a component id -> not needed

        // 1. start from a node, DFS to find connected nodes, mark all as visited
        // 2. find the next unvisited node (and inc the count), 
        // repeat from 1

        // 1. build adj list first
        unordered_map<int, vector<int>> adj_list;
        for (auto e: edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        // 2. for loop from 0 to n-1
        int comp_cnt = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                continue; // skip
            }
            // node of a new component
            visited[i] = true;
            dfs(i, adj_list, visited);

            comp_cnt += 1;
        }

        return comp_cnt;
    }
};
