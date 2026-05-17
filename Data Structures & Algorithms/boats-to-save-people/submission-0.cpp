class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // 1. sort (built-in)
        sort(people.begin(), people.end());

        // pair heaviest with lightest (if under limit)
        int boat_cnt = 0;
        int right = people.size() - 1;
        int left = 0;
        while (left <= right) {
            if (left == right) { // add extra one boat for the only one person left
                left += 1;
            } else if (people[right] + people[left] <= limit) {
                // pair
                right -= 1;
                left += 1;
            } else {
                // allow single person only
                right -= 1;
            }
            boat_cnt += 1;
        }

        return boat_cnt;
    }
};