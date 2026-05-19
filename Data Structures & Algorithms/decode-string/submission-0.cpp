class Solution {
public:
    string decodeString(string s) {
        stack<char> char_stack;
        for (auto c: s) {
            if (c == ']') {
                // construct the internal content
                string temp_str = "";
                while (char_stack.top() != '[') {
                    temp_str += char_stack.top();
                    char_stack.pop();
                }
                reverse(temp_str.begin(), temp_str.end());
                char_stack.pop(); // pop the corresponding [
                // handle the multiply
                int mult = 0;
                int pos = 1;
                while (true) {
                    if (char_stack.empty()) {
                        // conclude the mult
                        break;
                    } else if (isdigit(char_stack.top())) {
                        mult += (char_stack.top() - '0') * pos;
                        pos *= 10;
                        char_stack.pop();
                    } else { // non digit
                        // conclude the mult
                        break;
                    }
                }
                // n times the string and push to stack
                for (int i = 0; i < mult; i++) {
                    for (auto temp_c: temp_str) {
                        char_stack.push(temp_c);
                    }
                }
            } else {
                char_stack.push(c);
            }
        }

        string res = "";
        while (!char_stack.empty()) {
            res += char_stack.top();
            char_stack.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};