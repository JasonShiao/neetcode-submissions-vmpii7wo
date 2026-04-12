class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # Non-ordered (only check existence without caring about the order)
        # Required to be O(n) -> Cannot sort it, O(nlogn)
        numset = set()
        # 1. Store into a hash for fast search O(1)
        for num in nums:
            numset.add(num)

        # 2. Check if (val-1) exist for each num, if not val is a head
        headset = set()
        for num in nums:
            if (num - 1) not in numset:
                headset.add(num)
        
        # 3. for each head, try building sequence
        longest = 0
        for head in headset:
            cur = head
            length = 1
            while (cur + 1) in numset:
                length += 1
                cur += 1
            # sequence end, check/update length
            if length > longest:
                longest = length
                
        return longest