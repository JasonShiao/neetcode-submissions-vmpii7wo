class FirstUnique {
private:
    unordered_set<int> non_unique;
    unordered_set<int> unique;
    queue<int> q;
public:
    FirstUnique(vector<int>& nums) {
        // maintain the queue
        // use a set or map to book keep the non-unique value
        for (auto num: nums) {
            if (non_unique.find(num) != non_unique.end()) {
                // do nothing
            } else if (unique.find(num) != unique.end()) {
                // unique to non-unique
                non_unique.insert(num);
                unique.erase(num);
            } else {
                // from haven't seen to unique
                unique.insert(num);
                q.push(num);
            }
        }
    }
    
    int showFirstUnique() {
        while (!q.empty()) {
            int cand = q.front();
            if (non_unique.find(cand) == non_unique.end()) {
                return cand;
            } else {
                q.pop(); // house keeping the queue
            }
        }

        return -1; // no unique
    }
    
    void add(int value) {
        if (non_unique.find(value) != non_unique.end()) {
            // do nothing
        } else if (unique.find(value) != unique.end()) {
            // unique to non-unique
            non_unique.insert(value);
            unique.erase(value);
        } else {
            // from haven't seen to unique
            unique.insert(value);
            q.push(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
