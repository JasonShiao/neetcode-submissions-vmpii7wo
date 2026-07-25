class Solution {
public:
    int maxTransactions(vector<int>& transactions) {
        // Decision only made at negative transactions
        // Positive transactions are always included

        // 1. Maintain accumulated sum
        // 2. Put all the included negative transaction into a min_heap
        // Strategy:
        //   Once the accumulated sum < 0, pop from the negative transaction min heap
        //   add released balance to accumulated sum
        //   repeat until sum >= 0
        int tran_cnt = 0;
        int balance = 0;
        priority_queue<int, vector<int>, greater<int>> included_neg_trans_min_heap;
        for (int i = 0; i < transactions.size(); i++) {
            // include directly first
            balance += transactions[i];
            tran_cnt += 1;
            // update the neg trans heap
            if (transactions[i] < 0) {
                included_neg_trans_min_heap.push(transactions[i]);
            }
            // check balance and pop neg from heap until valid
            while (balance < 0) {
                balance -= included_neg_trans_min_heap.top();
                included_neg_trans_min_heap.pop();
                // Remember to dec tran_cnt
                tran_cnt -= 1;
            }
        }

        return tran_cnt;
    }
};
