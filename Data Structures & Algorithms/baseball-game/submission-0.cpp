class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score_stack;
        stack<int> temp_stack;
        int sum_score = 0;
        for (auto& op: operations) {
            if (op.compare(0,1,"+") == 0) {
                temp_stack.push(score_stack.top());
                score_stack.pop();
                temp_stack.push(score_stack.top());
                score_stack.pop();
                int sum = 0;
                while (temp_stack.size()) {
                    int temp_val = temp_stack.top();
                    sum += temp_val;
                    // move back val to score stack
                    score_stack.push(temp_val);
                    temp_stack.pop();
                }
                // add new score record
                score_stack.push(sum);
                sum_score += sum;
            } else if (op.compare(0,1,"D") == 0) {
                int double_top = score_stack.top() * 2;
                score_stack.push(double_top);
                sum_score += double_top;
            } else if (op.compare(0,1,"C") == 0) {
                sum_score -= score_stack.top();
                score_stack.pop();
            } else {
                int new_score = stoi(op);
                score_stack.push(new_score);
                sum_score += new_score;
            }
        }

        return sum_score;
    }
};