class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Modified Dijkstra's
        // Cummulative prob are multiplied instead of sum
        // Always select the max prob -> no regret needed

        // build adj list from edges
        // node i -> node j -> succ_prob
        unordered_map<int, unordered_map<int, double>> adj;
        for (int i = 0; i < edges.size(); i++) {
            // undirected -> add both dir
            adj[edges[i][0]][edges[i][1]] = succProb[i];
            adj[edges[i][1]][edges[i][0]] = succProb[i];
        }

        // The storage: <node_i, (max_prob to neigh_node)>
        unordered_map<int, double> max_prob_map;
    
        // Calc max prob
        auto cmp_prob = [](const pair<int, double>& a, const pair<int, double>& b) {
            return a.second < b.second;
        };
        priority_queue<pair<int, double>, vector<pair<int, double>>, decltype(cmp_prob)> max_prob_heap;
        max_prob_heap.push({start_node, 1.0});
        while (!max_prob_heap.empty()) {
            auto p = max_prob_heap.top();
            max_prob_heap.pop();
            int node_idx = p.first;
            double node_accum_prob = p.second;

            // process the node
            // reject if visited?
            if (max_prob_map.find(node_idx) != max_prob_map.end()) {
                continue;
            }

            max_prob_map[node_idx] = node_accum_prob; // path prob
            for (auto [neigh_idx, prob]: adj[node_idx]) {
                max_prob_heap.push({neigh_idx, node_accum_prob * prob});
            }

        }

        // return the result
        if (max_prob_map.find(end_node) != max_prob_map.end()) {
            return max_prob_map[end_node];
        } else {
            return 0; // No path from start to end
        }
        

    }
};