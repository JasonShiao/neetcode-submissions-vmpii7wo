class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # 1. Non sorted -> sort it "in-place"
        # 2. Cannot use extra memory: O(1) only other than the nums
        #    i.e. cannnot use hash map

        # iterate from start -> select as the first index in the triplet
        nums = sorted(nums)
        triplets = []
        for i, num in enumerate(nums):
            if i >= (len(nums) - 2):
                break
            
            # Notice 1: Avoid duplicate (already found all triplets starting with nums[i])
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            target = -num
            left = i + 1
            right = len(nums) - 1
            while left < right:
                if nums[left] + nums[right] < target:
                    left += 1
                elif nums[left] + nums[right] > target:
                    right -= 1
                else:
                    triplets.append([num, nums[left], nums[right]])
                    
                    # Notice 2: Keep finding without duplicate
                    left += 1
                    right -= 1
                    while left < right and nums[left] == nums[left-1]:
                        left += 1
                    while left < right and nums[right] == nums[right+1]:
                        right -= 1

        return triplets
