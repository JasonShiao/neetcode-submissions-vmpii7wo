class Solution {
public:
    bool dfs(unordered_map<int, unordered_set<int>>& prereq_graph,
            unordered_set<int>& visited_in_path, int i) {
        if (visited_in_path.find(i) != visited_in_path.end()) {
            return false; // cycle -> not doable
        }

        if (prereq_graph[i].empty()) { // already empty prereq -> doable
            return true;
        }

        visited_in_path.insert(i);
        for (auto prereq: prereq_graph[i]) {
            if (!dfs(prereq_graph, visited_in_path, prereq)) {
                return false; // any of prereq can't be done
            }
        }
        visited_in_path.erase(i); // backtracking (maintain visited for a single path)

        // Key part to reject duplicate search!!
        prereq_graph[i] = unordered_set<int>{};

        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build the graph
        // with a hash map (int coursN, vector<int> prereq)
        unordered_map<int, unordered_set<int>> prereq_graph;
        for (auto prereq: prerequisites) {
            prereq_graph[prereq[0]].insert(prereq[1]);
        }
        
        // Detect cycle in the graph starting from node 0, ..., numCourses - 1
        
        // use a visited set for "the current path"!!!
        unordered_set<int> visited_in_path;

        // for (int i = 0; i < numCourses; i++) {
        //     int cur = i;
        //     if (prereq_graph.find(cur))
        // }

        // DFS and remove the prereq if it can be taken
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(prereq_graph, visited_in_path, i)) {
                return false;
            }
        }

        return true;
    }
};
