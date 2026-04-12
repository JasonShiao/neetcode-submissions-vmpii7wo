class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_bank = {}
        for i,num in enumerate(nums):
            complement = target - num
            if complement in num_bank:
                return [num_bank[complement], i]
            else:
                num_bank[num] = i
        
        raise Exception('Unexpected')