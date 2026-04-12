class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket_stack;
        for (char c: s) {
            if (c == '[' || c == '(' || c == '{') {
                bracket_stack.push(c);
            } else {
                if (bracket_stack.size() == 0) {
                    return false;
                }
                if (c == ']') {
                    if (bracket_stack.top() != '[') {
                        return false;
                    }
                    bracket_stack.pop();
                } else if (c == ')') {
                    if (bracket_stack.top() != '(') {
                        return false;
                    }
                    bracket_stack.pop();
                } else if (c == '}') {
                    if (bracket_stack.top() != '{') {
                        return false;
                    }
                    bracket_stack.pop();
                }
            }
        }

        // Notice, don't forget this check
        if (bracket_stack.size() > 0) {
            return false;
        }

        return true;
    }
};
