class Solution {
public:
    string removeDuplicates(string s, int k) {
        // like 1-D candy crush block removal!!
        
        // for the stack -> maintain pair<char, cnt> as element
        stack<pair<char, int>> st;
        for (const auto& c: s) {
            if (!st.empty()) {
                if (c == st.top().first) {
                    int cnt = st.top().second;
                    if (cnt + 1 == k) {
                        // pop only
                        st.pop();
                    } else {
                        // pop and push a new cnt
                        st.pop();
                        st.push({c, cnt + 1});
                    }
                } else {
                    st.push({c, 1});
                }
            } else {
                st.push({c, 1});
            }
        }

        string res = "";
        while (!st.empty()) {
            // repeated n times
            for (int i = 0; i < st.top().second; i++) {
                res += st.top().first;
            }
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};