class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Without the restriction of at most k stops, 
        // it will be a typical shortest path problem

        // Bellman Ford


        // BFS from start and go through ALL of the edges for each iter
        // run for k iterations (k stops)
        // Complexity: O(k * E)
    
        // NOTE: We dequeue a node, along with its number of stops and current cost.
        //       If the number of stops exceeds the specified limit k, 
        //       we skip exploration from that node to avoid exceeding the maximum number of stops.

        // initialize adj list
        unordered_map<int, set<pair<int, int>>> adj; // src -> {<dest, price>}
        for (auto flight: flights) {
            adj[flight[0]].insert({flight[1], flight[2]});
        }

        unordered_map<int, int> cost; // i -> cost
        for (int i = 0; i < n; i++) {
            if (i == src) {
                cost[i] = 0;
            } else {
                cost[i] = INT_MAX;
            }
        }

        deque<tuple<int, int, int>> q; // <node, stop, new_cost>
        q.push_back(make_tuple(src, -1, 0));
        while (!q.empty()) {
            auto p = q.front();
            q.pop_front();

            if (get<1>(p) >= k) {
                // skip 
                // (because the path to next neighbor from this will > k)
                continue;
            }

            int new_cost = get<2>(p);
            // process
            for (auto nei: adj[get<0>(p)]) {
                if (new_cost + nei.second < cost[nei.first]) {
                    cost[nei.first] = new_cost + nei.second;
                    q.push_back(make_tuple(nei.first, get<1>(p)+1, cost[nei.first]));
                }
            }

        }

        // final cost
        if (cost[dst] == INT_MAX) {
            return -1;
        }
        return cost[dst];
    }
};
