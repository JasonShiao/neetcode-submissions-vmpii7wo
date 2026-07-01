class ZigzagIterator {
private:
    queue<int> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        // follow up: what if there are k vectors?

        int cur1 = 0;
        int cur2 = 0;
        while (cur1 < v1.size() || cur2 < v2.size()) {
            if (cur1 >= v1.size()) {
                q.push(v2[cur2]);
                cur2 += 1;
            } else if (cur2 >= v2.size()) {
                q.push(v1[cur1]);
                cur1 += 1;
            } else {
                // both smaller
                q.push(v1[cur1]);
                q.push(v2[cur2]);
                cur1 += 1;
                cur2 += 1;
            }
        }

    }

    int next() {
        int res = q.front();
        q.pop();
        return res;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
