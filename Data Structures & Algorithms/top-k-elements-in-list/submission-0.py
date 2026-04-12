import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        lookup = {}
        for num in nums:
            if num in lookup:
                lookup[num] += 1
            else:
                lookup[num] = 1
        
        # heapq is min heap (use negative count for max heap)
        neg_val_cnt_list = [(-cnt, num) for num, cnt in lookup.items()]
        
        max_heap = neg_val_cnt_list
        heapq.heapify(max_heap)

        top_k_list = []
        for _ in range(k):
            top_k_list.append(heapq.heappop(max_heap)[1])
        
        return top_k_list
