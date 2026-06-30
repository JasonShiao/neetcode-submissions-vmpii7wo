class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        // non-zero pos in mat1 
        // map to a set of cols that is non-zero (and that will affect multiplication)

        // (i, j) in mat1, only cares about (j, k) in mat2
        // and the result is stored (accumulated +=) into (i, k) cell
    
        vector<vector<int>> res(mat1.size(), vector<int>(mat2[0].size(), 0));

        map<pair<int, int>, set<int>> relatives; // <i,j> in mat1 -> {...} cols idx in mat2
        // find non zero in mat1
        for (int r = 0; r < mat1.size(); r++) {
            for (int c = 0; c < mat1[0].size(); c++) {
                if (mat1[r][c] == 0) {
                    continue;
                }

                for (int c2 = 0; c2 < mat2[0].size(); c2++) {
                    if (mat2[c][c2] == 0) {
                        continue;
                    }

                    //relatives[{r, c}].insert(c2);
                    res[r][c2] += mat1[r][c] * mat2[c][c2];
                }
            }
        }

        return res;
    
    }
};
