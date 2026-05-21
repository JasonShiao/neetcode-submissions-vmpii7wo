struct Project {
    int profit;
    int capital;
};

struct CompareMaxProfit {
    bool operator()(const Project& a, const Project& b) {
        return a.profit < b.profit;
    }
};

struct CompareMinCapital {
    bool operator()(const Project& a, const Project& b) {
        return a.capital > b.capital;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // affordable pool: max_heap with profit
        priority_queue<Project, vector<Project>, CompareMaxProfit> profit_max_heap;
        // not-affordable pool: min_heap with capital
        priority_queue<Project, vector<Project>, CompareMinCapital> capital_min_heap;

        // First push to capital heap 
        for (int i = 0; i < profits.size(); i++) {
            Project proj;
            proj.profit = profits[i];
            proj.capital = capital[i];
            capital_min_heap.push(proj);
        }

        int proj_done = 0;
        int current_cap = w;
        while (proj_done < k) {
            // move affordable projects to profit heap
            while (!capital_min_heap.empty() && 
                    capital_min_heap.top().capital <= current_cap) {
                
                profit_max_heap.push(capital_min_heap.top());
                capital_min_heap.pop();
            }

            // Extract the max profit proj from profit heap
            // need to assert heap non empty
            if (profit_max_heap.empty()) {
                break;
            }

            current_cap += profit_max_heap.top().profit;
            profit_max_heap.pop();

            proj_done += 1;
        }

        return current_cap;
    }
};