class Solution {
public:
    int minTimeRecursion(unordered_map<int, vector<int>>& adj_list, 
                        vector<bool>& hasApple,
                        int from, int curr) {
        int res = 0;
        for (auto adj: adj_list[curr]) {
            if (adj == from) {
                continue;
            }
            auto t = minTimeRecursion(adj_list, hasApple, 
                                    curr, adj);
            // whether we should dive into the adj branch
            if (t > 0 || hasApple[adj]) {
                res += (t + 2); // forward & backward: 2
            }
        }

        return res;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // NOTICE: a tree has no cycle! no need to worry about that
        
        // if there is apple in the left child or subtree of left child -> should search left
        // similar to the right branch

        // Create the adj list
        unordered_map<int, vector<int>> adj_list;
        for (auto edge: edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        return minTimeRecursion(adj_list, hasApple, -1, 0);
    }
};