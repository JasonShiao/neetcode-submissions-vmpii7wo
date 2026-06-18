class Solution {
public:
    int findRoot(int i, unordered_map<int, int>& parent_map) {
        while (parent_map[i] != i) {
            i = parent_map[i];
        }
        return i;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // key insight: V = E + 1
        // Union by rank
        // Merge by root -> if root overlapped -> cycle found
        // NOTICE: we can' directly maintain a root_map
        //         we can only maintain parent_map
        //         need to find the root by parent iteratively 
        
        // 1. make each node a tree and the root is itself
        unordered_map<int, int> parent_map;
        for (int i = 1; i <= edges.size(); i++) {
            parent_map[i] = i;
        }

        // 2. when merging, attach root to another root
        for (auto edge: edges) {
            // check if two root have already matched
            int root_1 = findRoot(edge[0], parent_map);
            int root_2 = findRoot(edge[1], parent_map);
            if (root_1 == root_2) {
                return edge;
            }
            // not -> merge
            if (root_1 < root_2) {
                parent_map[root_2] = root_1;
            } else {
                parent_map[root_1] = root_2;
            }
        }

    }
};
