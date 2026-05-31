class Solution {
public:
    // BFS shortest path
    int bfs(string start_state, unordered_map<string, int>& dp_lookup, 
            vector<string>& deadends, string target) {
        
        // use to reject entering deadend
        for (auto dead: deadends) {
            dp_lookup[dead] = -1;
        }

        // Edge case: start_state in deadends
        if (dp_lookup[start_state] == -1) {
            return -1;
        }

        queue<string> q;
        q.push(start_state);
        dp_lookup[start_state] = 0;

        while (!q.empty()) {
            string state = q.front();
            q.pop();

            if (state == target) {
                return dp_lookup[state];
            }

            // check neighbors
            for (int i = 0; i < 4; i++) {
                // +1
                string neigh = state;
                neigh[i] = (neigh[i] - '0' + 1) % 10 + '0';
                if (dp_lookup.find(neigh) == dp_lookup.end()) {
                    // update dp before push to avoid repeat
                    dp_lookup[neigh] = dp_lookup[state] + 1;
                    q.push(neigh);
                }
                // -1
                neigh = state;
                neigh[i] = (neigh[i] - '0' + 9) % 10 + '0';
                if (dp_lookup.find(neigh) == dp_lookup.end()) {
                    // update dp before push to avoid repeat
                    dp_lookup[neigh] = dp_lookup[state] + 1;
                    q.push(neigh);
                }
            }

        }

        return -1;

    }

    int openLock(vector<string>& deadends, string target) {
        // bfs from 0000
        // for neighbors: 0001, 0010, 0100, 1000, 9000, 0900, 0090, 0009

        unordered_map<string, int> dp_lookup;
        return bfs("0000", dp_lookup, deadends, target);
    }
};