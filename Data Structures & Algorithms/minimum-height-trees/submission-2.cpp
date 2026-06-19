class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // start from leaves, diffuse and keep removing the leaves
        // can be thought of a reverse bfs (from leaf instead of root)

        // At each iteration, the removed leaves ALWAYS have higher height
        //                    than the remaining nodes 
        // (because it must pass through at least one remaining nodes for the longest path)

        // 0. special case: 1 node only
        if (n == 1) {
            return {0};
        }

        // 1. create adj list from edges
        unordered_map<int, set<int>> adj;
        for (auto e: edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        // 2. Extract leaf nodes (for 1st iter)
        deque<int> leaves; // NOTICE: the use of deque!
        unordered_map<int, int> edge_cnt;
        for (auto [node_idx, neighbors]: adj) {
            if (neighbors.size() == 1) {
                leaves.push_back(node_idx);
            }
            edge_cnt[node_idx] = neighbors.size();
        }

        vector<int> res;
        while (!leaves.empty()) {
            // terminate condition: only <= 2 nodes remain (at the start of iter)
            if (n <= 2) {
                // remaining in the leaves queue
                for (auto leaf: leaves) {
                    res.push_back(leaf);
                }
            }

            // store the cnt for current layer, 
            // the leaves queue will be changed in the for loop
            int cur_leaf_cnt = leaves.size();
            
            // remove leaves
            // NOTICE: don't need to maintain visited,
            // the edge cnt itself is able to ensure the condition
            for (int i = 0; i < cur_leaf_cnt; i++) {
                int cur_leaf = leaves.front();
                leaves.pop_front();

                n -= 1; // the remaining nodes

                for (auto nei: adj[cur_leaf]) {
                    edge_cnt[nei] -= 1;
                    if (edge_cnt[nei] == 1) {
                        leaves.push_back(nei);
                    }
                }
            }

            
        }

        return res;
    }
};