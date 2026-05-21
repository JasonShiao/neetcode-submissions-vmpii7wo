struct Task {
    int index;
    int available_time;
    int process_time;
};

struct CompareAvailableTime {
    bool operator()(const Task& a, const Task& b) const {
        return a.available_time > b.available_time;
    }
};

struct CompareProcessTime {
    bool operator()(const Task& a, const Task& b) const {
        if (a.process_time == b.process_time) {
            return a.index > b.index;
        }
        return a.process_time > b.process_time;
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // 1. Prioritize the task with max processing time
        // max heap for available tasks
        // 2. also create a min heap for task in custody (not available to process yet)
        
        priority_queue<Task, vector<Task>, CompareProcessTime> available_tasks;
        priority_queue<Task, vector<Task>, CompareAvailableTime> custody_tasks;
        // First, put all tasks in custody
        for (int i = 0; i < tasks.size(); i++) {
            Task tmp;
            tmp.available_time = tasks[i][0];;
            tmp.process_time = tasks[i][1];
            tmp.index = i;
            custody_tasks.push(tmp);
        }

        long long cur_time = 0;
        vector<int> res;
        // Move to max heap as time goes by
        while (!available_tasks.empty() || !custody_tasks.empty()) {
            // if idle -> drag at least one from custody 
            //       and fast forward to the avaialble time
            if (available_tasks.empty()) {
                // get one from the  custody
                auto t = custody_tasks.top();
                available_tasks.push(t);
                custody_tasks.pop();
                // Notice: take the max
                cur_time = max((long long)t.available_time, cur_time);
            }

            // release tasks from custody for current time
            while (!custody_tasks.empty() &&
                    custody_tasks.top().available_time <= cur_time) {
                // move from custody to available
                available_tasks.push(custody_tasks.top());
                custody_tasks.pop();
            }

            // process a task and update cur_time
            if (!available_tasks.empty()) {
                auto t = available_tasks.top();
                available_tasks.pop();
                cur_time += t.process_time;
                res.push_back(t.index);
            }
        }

        return res;
    }
};