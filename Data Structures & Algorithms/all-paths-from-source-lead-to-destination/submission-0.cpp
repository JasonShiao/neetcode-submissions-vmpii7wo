class Solution {
public:
    bool backtrack(int src, int dest, 
                    vector<vector<int>>& adj_list, 
                    vector<bool>& visited) {
        // recursive till the end

        if (adj_list[src].size() == 0) { // reach the terminal
            // result depends on whether src == dest
            return src == dest;
        }

        visited[src] = true;
        for (auto neigh: adj_list[src]) {
            if (visited[neigh]) {
                // already visited -> a cycle detected
                return false;
            }
            // check if all paths from next step reach dest
            if (!backtrack(neigh, dest, adj_list, visited)) {
                return false;
            }
        }

        visited[src] = false;
        return true;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        // handle cycles and self-loop!!

        // First intuition: DFS backtracking
        // if there is any cycle -> return false
        // if the final node is not dest -> return false

        // 1. build adj list
        vector<vector<int>> adj_list(n, vector<int>());
        for (auto e: edges) {
            adj_list[e[0]].push_back(e[1]);
        }

        vector<bool> visited(n, false);
        return backtrack(source, destination, adj_list, visited);
    }
};
