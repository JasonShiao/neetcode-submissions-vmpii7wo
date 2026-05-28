class Solution {
public:
    void backtracking(unordered_map<int, unordered_set<int>>& prereq_graph,
                    int i, 
                    unordered_set<int>& visited_in_path,
                    unordered_set<int>& done_added,
                    unordered_map<int, unordered_set<int>>& indirect_prereq_graph) {
        if (done_added.find(i) != done_added.end()) {
            return;
        }

        visited_in_path.insert(i);
        for (auto prereq: prereq_graph[i]) {
            // backtracking step into prereq (to update indirect prereq)
            backtracking(prereq_graph, prereq, 
                        visited_in_path, done_added, indirect_prereq_graph);
            // Add set of complete indirect prereq of direct prereq
            for (auto p: indirect_prereq_graph[prereq]) {
                indirect_prereq_graph[i].insert(p);
            }
            // add the direct prereq
            indirect_prereq_graph[i].insert(prereq);
        }

        done_added.insert(i);
        visited_in_path.erase(i);
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Key: the given prereq graph has no cycles!

        // build the direct prereq graph (adj list)
        unordered_map<int, unordered_set<int>> prereq_graph;
        for (auto prereq: prerequisites) {
            prereq_graph[prereq[1]].insert(prereq[0]);
        }

        // backtracking to build the indirect prereq graph
        unordered_set<int> visited_in_path;
        unordered_set<int> done_added;
        unordered_map<int, unordered_set<int>> indirect_prereq_graph;
        for (int i = 0; i < numCourses; i++) {
            backtracking(prereq_graph, i, visited_in_path, 
                        done_added, indirect_prereq_graph);
        }

        // Handle queries
        vector<bool> res;
        for (auto q: queries) {
            if (indirect_prereq_graph[q[1]].find(q[0]) == 
                indirect_prereq_graph[q[1]].end()) { // not found
                res.push_back(false);
            } else {
                res.push_back(true);
            }
        }

        return res;

    }
};