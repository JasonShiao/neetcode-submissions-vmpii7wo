class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            // NOTE: must start from 0!!!!
            for (int j = 0; j < words[i].size(); j++) {
                if (j >= words.size() || i >= words[j].length()) {
                    return false;
                }

                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }

        return true;
    }
};
