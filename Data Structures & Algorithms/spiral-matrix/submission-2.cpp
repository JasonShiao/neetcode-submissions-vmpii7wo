enum class Dir {
    RIGHT,
    DOWN,
    LEFT,
    UP
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        Dir current_dir = Dir::RIGHT;
        int i = 0; // row
        int j = 0; // col
        int row_upperbound = matrix.size();
        int row_lowerbound = -1;
        int col_upperbound = matrix[0].size();
        int col_lowerbound = -1;

        vector<int> res;
        while (true) {
            // process current cell
            res.push_back(matrix[i][j]);
            
            // will change at most 90 degree clockwise (won't be 180 or 270)
            // change direction and update bound if reaching bound and 
            switch (current_dir) {
                case Dir::RIGHT:
                    // check col upperbound
                    if (j + 1 == col_upperbound) {
                        current_dir = Dir::DOWN;
                        row_lowerbound = i;
                    }
                    break;
                case Dir::DOWN:
                    if (i + 1 == row_upperbound) {
                        current_dir = Dir::LEFT;
                        col_upperbound = j;
                    }
                    break;
                case Dir::LEFT:
                    if (j - 1 == col_lowerbound) {
                        current_dir = Dir::UP;
                        row_upperbound = i;
                    }
                    break;
                case Dir::UP:
                    if (i - 1 == row_lowerbound) {
                        current_dir = Dir::RIGHT;
                        col_lowerbound = j;
                    }
                    break;
                default:
                    break;
            }

            // move to next cell
            switch (current_dir) {
                case Dir::RIGHT:
                    j += 1;
                    break;
                case Dir::DOWN:
                    i += 1;
                    break;
                case Dir::LEFT:
                    j -= 1;
                    break;
                case Dir::UP:
                    i -= 1;
                    break;
                default:
                    break;
            }
            
            // break if reach bound even changed direction clockwise
            if (i == row_lowerbound || i == row_upperbound ||
                j == col_upperbound || j == col_lowerbound) {
                break;
            }

        }
        return res;
    }
};
