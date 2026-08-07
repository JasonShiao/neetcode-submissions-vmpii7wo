/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // Insight:
        // each call of know() can eliminate "exact" one person from the pool!!
        // if true, eliminate a (celebrity cannot know any other)
        // if false, eliminate b (celebrity must be known by anyone)

        // brute force: O(n^2)
        // optimize with insight: O(n) at most n-1 elimination!
        // Insight 2: tricks -> the remaining idx from know is assigned as the next candidate
        //            instead of maintaining a candidate pool!!
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (!knows(i, candidate)) { // if i doesn't know the candidate
                candidate = i;
            } else {
                // keeps the candidate
            }
        }
        // this only result in a candidate but not guarantee!!
        // must check from all again
        for (int i = 0; i < n; i++) {
            if (i == candidate) continue;
            if (!knows(i, candidate) || knows(candidate, i)) {
                return -1;
            }
        }

        return candidate;
    }
};
