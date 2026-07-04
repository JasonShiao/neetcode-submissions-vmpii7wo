class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int curProdCnt = 0;
        int curProd = -1;

        int cur1 = 0;
        int subcur1 = 0;
        int cur2 = 0;
        int subcur2 = 0;
        vector<vector<int>> res;
        while (true) {
            if (cur1 == encoded1.size()) {
                break;
            }

            int newProd = encoded1[cur1][0] * encoded2[cur2][0];

            if (newProd == curProd) {
                curProdCnt += 1;
            } else {
                // conclude the previous repeated
                if (curProdCnt > 0) {
                    res.push_back({curProd, curProdCnt});
                }
                curProd = newProd;
                curProdCnt = 1;
            }
            
            subcur1 += 1;
            subcur2 += 1;
            if (subcur1 >= encoded1[cur1][1]) {
                subcur1 = 0;
                cur1 += 1;
            }
            if (subcur2 >= encoded2[cur2][1]) {
                subcur2 = 0;
                cur2 += 1;
            }

        }

        // handle the remaining
        if (curProdCnt > 0) {
            res.push_back({curProd, curProdCnt});
        }

        return res;
    }
};
