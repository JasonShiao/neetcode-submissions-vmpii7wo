/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class Solution {
private:
    int max_depth = 0;
public:
    pair<int, int> recursive(vector<NestedInteger>& nestedList, int depth) {
        // return depth_sum, normal sum
        int normal_sum = 0;
        int depth_sum = 0;

        // maintain/update the max depth
        max_depth = max(max_depth, depth);

        for (auto n: nestedList) {
            if (n.isInteger()) {
                normal_sum += n.getInteger();
                depth_sum += n.getInteger() * (depth - 1);
            } else {
                auto p = recursive(n.getList(), depth + 1);
                depth_sum += p.first;
                normal_sum += p.second;
            }
        }
        return {depth_sum, normal_sum};
    }

    int depthSumInverse(vector<NestedInteger>& nestedList) {
        auto p = recursive(nestedList, 1);
        int res = max_depth * p.second - p.first;
        // cout << max_depth << endl;
        // cout << p.second << endl;
        // cout << p.first << endl;
        return res;
    }
};
