class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Better solution: check all 3 entries at the same time
        vector<bool> check = {false, false, false};
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] ||
                triplets[i][2] > target[2]) {
                continue;
            }

            if (triplets[i][0] == target[0]) {
                check[0] = true;
            }
            if (triplets[i][1] == target[1]) {
                check[1] = true;
            }
            if (triplets[i][2] == target[2]) {
                check[2] = true;
            }
        }

        return check[0] && check[1] && check[2];
    }
    // My first solution: redundant subsets:
    // bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    //     // select the 1st subset with triplet[0] <= target[0]
    //     // from the 1st subset -> further subset with triplet[1] <= target[1]
    //     // select the the final subset with triplet[2] <= target[2]
    //     unordered_set<int> subset;
    //     for (int i = 0; i < triplets.size(); i++) {
    //         if (triplets[i][0] <= target[0]) {
    //             subset.insert(i);
    //         }
    //     }
    //     unordered_set<int> second_subset;
    //     for (auto i: subset) {
    //         if (triplets[i][1] <= target[1]) {
    //             second_subset.insert(i);
    //         }
    //     }
    //     unordered_set<int> third_subset;
    //     for (auto i: second_subset) {
    //         if (triplets[i][2] <= target[2]) {
    //             third_subset.insert(i);
    //         }
    //     }

    //     // check whether {max(.), max(.), max(.)} == target
    //     vector<int> max_or = {0, 0, 0};
    //     for (auto i: third_subset) {
    //         max_or[0] = max(max_or[0], triplets[i][0]);
    //         max_or[1] = max(max_or[1], triplets[i][1]);
    //         max_or[2] = max(max_or[2], triplets[i][2]);
    //     }

    //     if (target[0] == max_or[0] && target[1] == max_or[1] && 
    //         target[2] == max_or[2]) {
    //         return true;
    //     } else {
    //         return false;
    //     }
    // }
};
