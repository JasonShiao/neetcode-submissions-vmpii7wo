class Solution {
public:
    string simplifyPath(string path) {
        string temp_pattern;
        deque<string> path_stack;
        for (auto c: path) {
            if (c == '.') {
                temp_pattern += c;
            } else if (c == '/') {
                // process the temp_pattern
                if (temp_pattern.length() == 0) {
                    // do nothing
                } else if (temp_pattern == ".") {
                    // do nothing
                } else if (temp_pattern == "..") {
                    if (!path_stack.empty()) {
                        path_stack.pop_back();
                    }
                } else {
                    // a dir
                    path_stack.push_back(temp_pattern);
                }
                // clear
                temp_pattern = "";
            } else {
                temp_pattern += c;
            }
        }

        // process & clean the remaining pattern
        if (temp_pattern.length() == 0) {
            // do nothing
        } else if (temp_pattern == ".") {
            // do nothing
        } else if (temp_pattern == "..") {
            if (!path_stack.empty()) {
                path_stack.pop_back();
            }
        } else {
            // a dir
            path_stack.push_back(temp_pattern);
        }

        // construct the simplified string
        string res;
        while (!path_stack.empty()) {
            res += "/";
            res.append(path_stack.front());
            path_stack.pop_front();
        }

        if (res.empty()) {
            res = "/";
        }

        return res;
    }
};