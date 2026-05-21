struct Node {
    char c;
    int remain;
    int next_avail_pos;
};

struct CompareRemain {
    bool operator()(Node& a, Node& b) {
        return a.remain < b.remain;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        // similar to scheduler with cool time
        // Tips:
        // 1. use the most frequent char if available
        // 2. put to cool down queue with cool time = 1 (i.e. next avail pos = pos + 2)
        
        // special condition differ from scheduler: 
        //   cannot have idle
        unordered_map<char, int> remain_map;
        priority_queue<Node, vector<Node>, CompareRemain> max_freq_heap;
        queue<Node> cool_down;

        for (auto c: s) {
            remain_map[c] += 1;
        }

        // create node and add to max heap
        for (const auto& [c, remain]: remain_map) {
            Node tmp;
            tmp.c = c;
            tmp.remain = remain;
            tmp.next_avail_pos = 0;
            max_freq_heap.push(tmp);
        }

        string res = "";
        int pos = 0;
        while (!max_freq_heap.empty() || !cool_down.empty()) {
            while (!cool_down.empty() && cool_down.front().next_avail_pos <= pos) {
                // move from cool down to max heap
                max_freq_heap.push(cool_down.front());
                cool_down.pop();
            }

            if (max_freq_heap.empty()) { // failed: no idle allowed
                return "";
            }

            // process and move to cool down
            auto node = max_freq_heap.top();
            max_freq_heap.pop();
            res += node.c;
            node.remain -= 1;
            if (node.remain > 0) {
                node.next_avail_pos = pos + 2;
                cool_down.push(node);
            }

            pos += 1;
        }

        return res;

    }
};