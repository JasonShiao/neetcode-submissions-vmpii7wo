class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # Key: Prefix mult & Suffix mult
        # Prefix: a_0 * a_1 * ... a_i-1
        # Suffix: a_n * a_n-1 * ... a_i+1

        prefix = [1]
        prefix_accum = 1
        for num in nums:
            prefix_accum *= num
            prefix.append(prefix_accum)

        suffix = [1]
        suffix_accum = 1
        for num in reversed(nums):
            suffix_accum *= num
            suffix.append(suffix_accum)
        
        result = []
        for i in range(len(nums)):
            result.append(prefix[i] * suffix[len(nums) - i - 1])
        
        return result