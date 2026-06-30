class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int cur1 = 0;
        int cur2 = 0;

        // NOTICE the condition for while loop
        while (cur1 < s.length() || cur2 < t.length()) {
            if (s[cur1] == t[cur2]) {
                cur1 += 1;
                cur2 += 1;
            } else {
                // the edit condition
                if (s.length() < t.length()) {
                    // insert s or delete t doesn't matter -> same result
                    if (s.substr(cur1) != t.substr(cur2+1)) {
                        return false;
                    } else {
                        return true;
                    }
                } else if (s.length() > t.length()) {
                    // insert t or delete s doesn't matter -> same result
                    if (s.substr(cur1+1) != t.substr(cur2)) {
                        return false;
                    } else {
                        return true;
                    }
                } else {
                    if (s.substr(cur1+1) != t.substr(cur2+1)) {
                        return false;
                    } else {
                        return true;
                    }
                }
            }

        }

        // NOTICE: exact the same -> no edit
        return false;
    }
};
