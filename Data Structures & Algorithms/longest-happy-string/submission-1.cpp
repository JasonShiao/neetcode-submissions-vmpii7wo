struct Node {
    char c;
    int remain;
    int next_avail_pos;
};

struct CompareRemain {
    bool operator()(const Node& a, const Node& b) {
        return a.remain < b.remain;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // select the char with max remaining but
        // for every consecutive -> have a cool down time 1
        priority_queue<Node, vector<Node>, CompareRemain> max_heap;
        queue<Node> cool_down;
        Node tmp;
        if (a > 0) {
            tmp.c = 'a';
            tmp.remain = a;
            tmp.next_avail_pos = 0;
            max_heap.push(tmp);
        }
        if (b > 0) {
            tmp.c = 'b';
            tmp.remain = b;
            max_heap.push(tmp);
        }
        if (c > 0) {
            tmp.c = 'c';
            tmp.remain = c;
            max_heap.push(tmp);
        }

        char prev_c = ' ';
        int pos = 0;
        string res = "";
        while (true) {
            while (!cool_down.empty() && 
                    cool_down.front().next_avail_pos <= pos) {
                max_heap.push(cool_down.front());
                cool_down.pop();
            }

            if (max_heap.empty()) {
                break;
            }

            // get the char with max remaining cnt
            Node node = max_heap.top();
            max_heap.pop();
            res += node.c;
            node.remain -= 1;
            // check if still remaining
            if (node.remain > 0) {
                if (prev_c == node.c) {
                    // move into cool down
                    node.next_avail_pos = pos + 2;
                    cool_down.push(node);
                } else {
                    // push to heap again
                    node.next_avail_pos = pos + 1;
                    max_heap.push(node);
                }
            } 

            prev_c = node.c;

            pos += 1;
        }

        return res;
    }
};