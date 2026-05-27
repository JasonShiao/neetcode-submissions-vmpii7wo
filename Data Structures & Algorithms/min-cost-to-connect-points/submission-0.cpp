class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // 1. build adj list of graph (should we?)
        // map<pair<int, int>, vector<pair<int, int>>> adj;
        // for (auto p: points) {
        //     adj[{p[0], p[1]}].push_back()
        // }

        // 2. Process min heap (storing edges (node_i->node_j))
        auto manhattan_dist = [&](const int& a, const int& b) {
            return abs(points[a][0] - points[b][0]) + 
                    abs(points[a][1] - points[b][1]);
        };
        auto cmp_dist = [&](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) > get<2>(b);
        };
        int total_dist = 0;
        unordered_set<int> visited;
        priority_queue<tuple<int, int, int>, 
                        vector<tuple<int, int, int>>, 
                        decltype(cmp_dist)> min_heap(cmp_dist);
        // Initialize the heap for the first node and its edges
        // (i.e. edges from node 0 to all the other points)
        for (int i = 1; i < points.size(); i++) {
            min_heap.push({0, i, manhattan_dist(0, i)});
        }
        visited.insert(0); // mark visited

        while (!min_heap.empty()) {
            auto edge = min_heap.top();
            min_heap.pop();
            int start_node = get<0>(edge);
            int end_node = get<1>(edge);
            int dist = get<2>(edge);

            // reject if visited
            if (visited.find(end_node) != visited.end()) {
                continue;
            }

            total_dist += dist;
            visited.insert(end_node);
            // add all unvisited points
            for (int i = 0; i < points.size(); i++) {
                if (visited.find(i) == visited.end()) {
                    // push to heap
                    min_heap.push({end_node, i, manhattan_dist(end_node, i)});
                }
            }

        }
        
        return total_dist;

    }
};
