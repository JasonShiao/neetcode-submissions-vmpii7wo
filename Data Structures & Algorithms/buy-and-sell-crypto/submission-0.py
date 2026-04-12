class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Key: only single day for buy and single day for sell
        
        # the r pointer search for max sell price
        # At the same time, the r pointer also help search for the min for l pointer
        l = 0
        r = 1
        max_profit = 0
        while r < len(prices):
            if prices[l] < prices[r]:
                # check profit
                profit = prices[r] - prices[l]
                max_profit = max(max_profit, profit)
            else:
                l = r
            r += 1
        
        return max_profit