class Solution {
public:
    string predictPartyVictory(string senate) {
        // each senator "kill" the senator from the other party appear first
        // until only one party exist

        queue<int> r_q;
        queue<int> d_q;

        for(int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R') {
                r_q.push(i);
            } else {
                d_q.push(i);
            }
        }

        // "kill" the other senator and then get to the back of queue
        int i = senate.length();
        while (!r_q.empty() && !d_q.empty()) {
            if (r_q.front() < d_q.front()) {
                d_q.pop();
                auto cur = r_q.front();
                r_q.push(i);
                r_q.pop();
            } else {
                r_q.pop();
                auto cur = d_q.front();
                d_q.push(i);
                d_q.pop();
            }
            i++;
        }

        if (r_q.empty()) {
            return "Dire";
        } else {
            return "Radiant";
        }
    }
};