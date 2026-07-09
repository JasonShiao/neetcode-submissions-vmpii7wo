class Solution {
public:
    string parseTernary(string expression) {
        // Key: all numbers are one-digit number!!

        stack<char> st;
        // Key right-to-left associative!!!
        for (auto rit = expression.rbegin(); rit != expression.rend(); rit++) {
            char c = *rit;
            if (!st.empty() && st.top() == '?') {
                // all the right chars of ? are on the stack 
                // second res is bottom
                // first res is upper
                st.pop(); // pop the '?'

                // Key: the current c can only be 'T' or 'F' when top is '?'
                bool isFirst = (c == 'T');
                char first = st.top();
                st.pop();
                st.pop(); // ':'
                char second = st.top();
                st.pop();

                if (isFirst) {
                    st.push(first);
                } else {
                    st.push(second);
                }
            } else {
                st.push(c);
            }
        }

        string res = "";
        res += st.top();

        return res;
    }
};
