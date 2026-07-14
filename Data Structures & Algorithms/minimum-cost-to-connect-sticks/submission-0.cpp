class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        // 1. each connect -> reduce one stick
        // Insight: the total number of connection is fixed
        //         minimize each connection -> always select the shortest

        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (auto stick: sticks) {
            min_heap.push(stick);
        }

        int total_cost = 0;
        while (min_heap.size() > 1) {
            // pop 2 elements and push (merged) 1 element
            int shortest = min_heap.top();
            min_heap.pop();
            int second_shortest = min_heap.top();
            min_heap.pop();
            
            int cost = shortest + second_shortest;
            total_cost += cost;
            min_heap.push(cost); // cost = length
        }

        return total_cost;
    }
};
