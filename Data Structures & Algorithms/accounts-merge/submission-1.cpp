class UnionFind {
public:
    // 0...n-1
    UnionFind(int n) {
        // initialize rank and parent
        rank = vector<int>(n, 1);

        for (auto i = 0; i < n; i++) {
            parent.push_back(i);
        }
    }

    int findRoot(int i) {
        while (i != parent[i]) {
            i =  parent[i];
        }
        return i;
    }
    bool union_two(int i1, int i2) {
        int r1 = findRoot(i1);
        int r2 = findRoot(i2);

        // Critical!!!!
        if (r1 != r2) { // not in the same group yet -> should union
            if (rank[r1] < rank[r2]) {
                rank[r2] += rank[r1];
                parent[r1] = r2;
            } else {
                rank[r1] += rank[r2];
                parent[r2] = r1;
            }
            return true;
        } else {
            // already in the same group -> do nothing
        }

        return false; // not in the same union
    }

private:
    // NOTE: rank not necessary in this case, 
    //       but it helps keep union tree shorter
    vector<int> rank; 
    vector<int> parent;
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind uf(accounts.size());

        // 1. Union find to group account indices sharing at least an email
        // each email is guanranteed to be mapped to an account idx
        unordered_map<string, int> email_account_map;
        for (int i = 0; i < accounts.size(); i++) {
            // iterate each email of the account
            for (int j = 1; j < accounts[i].size(); j++) {
                if (email_account_map.find(accounts[i][j]) == email_account_map.end()) {
                    // not found -> add one
                    email_account_map[accounts[i][j]] = i;
                } else {
                    //!!!!Critical!!!!!
                    // already mapped to an account 
                    // -> union two originally diff accounts
                    uf.union_two(i, email_account_map[accounts[i][j]]);
                }
            }
        }

        // 2. iterate through the email -> account map to create email group
        unordered_map<int, vector<string>> email_group;
        for (auto [email, account]: email_account_map) {
            // use root account as key so account in the same group can be determined
            email_group[uf.findRoot(account)].push_back(email);
        }

        // 3. sort and build result
        vector<vector<string>> res;
        for (auto [acc_idx, email_list]: email_group) {
            vector<string> grouped;
            grouped.push_back(accounts[acc_idx][0]);
            sort(email_list.begin(), email_list.end());
            for (auto email: email_list) {
                grouped.push_back(email);
            }
            
            res.push_back(grouped);
        }

        return res;
    }
};