class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        // process the local name
        // hash map/set to store the processed email string
    
        unordered_set<string> emails_set;
        for (auto email: emails) {
            bool domain = false;
            bool plus_sign = false;
            string tmp_s = "";
            for (int i = 0; i < email.length(); i++) {
                if (domain) { // append directly
                    tmp_s += email[i];
                } else {
                    if (email[i] == '.') continue; // ignore for local name
                    if (email[i] == '+') {
                        plus_sign = true;
                        continue;
                    }
                    if (email[i] == '@') {
                        domain = true;
                        tmp_s += email[i];
                    }
                    if (plus_sign) continue; // ignore all between '+' and '@'
                    // char in local name
                    tmp_s += email[i];
                }
            }
            emails_set.insert(tmp_s);
        }

        return emails_set.size();
    }
};