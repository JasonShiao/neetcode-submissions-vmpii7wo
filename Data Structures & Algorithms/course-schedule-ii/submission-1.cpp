class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> prereq_graph;
        // build the graph
        for (auto prereq: prerequisites) {
            prereq_graph[prereq[0]].insert(prereq[1]);
        }
        
        // Topological sort
        vector<int> res;
        unordered_set<int> visited_in_path;
        // no built-in union find in C++, use a set
        unordered_set<int> added;

        // post order dfs
        function<bool(int)> dfs = [&](int i) {
            if (visited_in_path.find(i) != visited_in_path.end()) {
                return false;
            }

            visited_in_path.insert(i); // mark for deeper layers
            // process (insert) all neighbors
            for (auto prereq: prereq_graph[i]) {
                if (!dfs(prereq)) {
                    return false;
                }
            }
            
            // Empty current prereq list to reject dup visit
            prereq_graph[i] = unordered_set<int>{};

            // then process (insert) itself if not added yet
            if (added.find(i) == added.end()) {
                res.push_back(i);
                added.insert(i);
            }

            visited_in_path.erase(i); // recover for backtracking

            return true;
        };

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return vector<int>{};
            }
        }

        return res;
    }
};
