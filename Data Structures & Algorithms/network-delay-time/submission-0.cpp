struct CompareDist {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // convert edges into adjacency list
        unordered_map<int, vector<pair<int, int>>> adj; // map i to pair(weight, neigh) 
        for (auto time: times) {
            adj[time[0]].push_back(make_pair(time[2], time[1]));
        }

        //unordered_set<int> determined; // put into this if node's shortest path is determined
        unordered_map<int, int> shortest_time;
        // (dist, node_id)
        priority_queue<pair<int,int>, vector<pair<int,int>>, CompareDist> min_dist_heap;
        // start from k
        min_dist_heap.push(make_pair(0, k)); // (dist, node_id)

        while (!min_dist_heap.empty()) {
            // (dist, node_id)
            auto p = min_dist_heap.top();
            min_dist_heap.pop();

            // NOTICE: MUST reject visited
            if (shortest_time.find(p.second) != shortest_time.end()) {
                continue;
            }

            shortest_time[p.second] = p.first;

            for (auto edge: adj[p.second]) {
                // edge: (neigh_id, dist)

                // skip if determined
                if (shortest_time.find(edge.second) != shortest_time.end()) {
                    continue;
                }

                min_dist_heap.push(make_pair(p.first + edge.first, edge.second));

            }
        }

        // find the max
        int min_complete_time = 0;
        if (shortest_time.size() < n) {
            return -1;
        }
        for (auto [key, val]: shortest_time) {
            if (val > min_complete_time) {
                min_complete_time = val;
            }
        }

        return min_complete_time;

    }
};
