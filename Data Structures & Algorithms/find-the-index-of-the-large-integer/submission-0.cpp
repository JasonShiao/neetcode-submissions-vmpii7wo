/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        // divide in the middle
        // the half with larger sum contains the target number

        // if [l, r] is even num of element: compare [l, m], [m+1, r]
        // if [l, r] is odd num of element: compare [l, m-1], [m+1, r]
        int l = 0;
        int r = reader.length() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if ((r - l) % 2) { // even num
                if (reader.compareSub(l, m, m+1, r) == 1) {
                    // between l and m
                    r = m;
                } else {
                    l = m+1;
                }
            } else { // odd num
                if (reader.compareSub(l, m-1, m+1, r) == 1) {
                    // between l and m-1
                    r = m-1;
                } else if (reader.compareSub(l, m-1, m+1, r) == -1) {
                    l = m+1;
                } else { // equal
                    return m;
                }
            }
        }

        return l;
    }
};
