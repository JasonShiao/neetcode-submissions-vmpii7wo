class Logger {
private:
    unordered_set<string> occupied_log_set;
    queue<pair<int, string>> timeout_queue;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        // when accepted, add to a set and push the timeout to a queue
        // use the queue to determine when we should pop from set

        // fast forward to the input timestamp
        while (!timeout_queue.empty() && 
                timeout_queue.front().first <= timestamp) {
            // pop from set and queue
            occupied_log_set.erase(timeout_queue.front().second);
            timeout_queue.pop();
        }

        if (occupied_log_set.empty()) {
            // add
            occupied_log_set.insert(message);
            timeout_queue.push({timestamp + 10, message});
            return true;
        } else {
            if (occupied_log_set.find(message) == occupied_log_set.end()) {
                // not occupied -> add and return true
                occupied_log_set.insert(message);
                timeout_queue.push({timestamp + 10, message});
                return true;
            } else {
                return false;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
