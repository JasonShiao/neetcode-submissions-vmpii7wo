class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        
        for (int i = 0; i < words.size(); i++) {
            // check curr col and curr row
            for (int j = 0; j < words[i].length(); j++) {
                if (i >= words[0].length() || j >= words.size()) {
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
