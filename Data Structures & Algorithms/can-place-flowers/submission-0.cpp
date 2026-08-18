class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // find the max possible plant cnt
        // if max >= n, true

        int i = 0;
        int max_plant_cnt = 0;
        while (i < flowerbed.size()) {
            if (flowerbed[i] == 1) {
                i += 2;
            } else {
                if ((i+1) < flowerbed.size() && flowerbed[i+1] == 1) {
                    // invalid plant pos
                    i += 3; // the next 2 are both invalid
                } else {
                    max_plant_cnt += 1;
                    i += 2; // the next pos is invalid after this plant
                }
            }
        }

        return n <= max_plant_cnt;
    }
};