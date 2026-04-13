class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operand_stack;
        for (string token: tokens) {
            if (token == "+") {
                int first = operand_stack.top();
                operand_stack.pop();
                int second = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(first + second);
            } else if (token == "-") {
                int first = operand_stack.top();
                operand_stack.pop();
                int second = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(second - first);
            } else if (token == "*") {
                int first = operand_stack.top();
                operand_stack.pop();
                int second = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(second * first);
            } else if (token == "/") {
                int first = operand_stack.top();
                operand_stack.pop();
                int second = operand_stack.top();
                operand_stack.pop();
                operand_stack.push(second / first);
            } else {
                operand_stack.push(stoi(token));
            }
        }
        
        return operand_stack.top();
    }
};
