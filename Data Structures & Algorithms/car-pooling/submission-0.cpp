struct Node {
    int location;
    int pick_or_drop; // + for pickup, - for drop-off
};

struct CompareLocation {
    bool operator()(const Node& a, const Node& b) {
        return a.location > b.location; // larger will be put to after
    }
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // pick up order based on the nearest "from" location
        // drop off order based on the nearest "to" location
        priority_queue<Node, vector<Node>, CompareLocation> min_loc_heap;
        for (auto& t: trips) {
            Node tmp;
            // pick up
            tmp.location = t[1];
            tmp.pick_or_drop = t[0]; // positive
            min_loc_heap.push(tmp);
            // drop off
            tmp.location = t[2];
            tmp.pick_or_drop = -t[0]; // negative
            min_loc_heap.push(tmp);
        }

        int current_load = 0;
        while (!min_loc_heap.empty()) {
            Node node = min_loc_heap.top();
            min_loc_heap.pop();
            current_load += node.pick_or_drop;
            // process all trips at the same location
            while (!min_loc_heap.empty() && 
                    min_loc_heap.top().location == node.location) {
                Node tmp = min_loc_heap.top();
                min_loc_heap.pop();
                current_load += tmp.pick_or_drop;
            }

            // at any location, the load > capacity -> invalid
            if (current_load > capacity) {
                return false;
            }

        }

        return true;
    }
};