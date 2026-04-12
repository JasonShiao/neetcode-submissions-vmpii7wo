class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # Key properties: 
        #   * Already sorted 
        # Key requirement: O(1) extra memory
        #     cannot store into an extra hash map (set)
        # Hint: Use two pointers (left and right)
        left = 0
        right = len(numbers) - 1
        while left < right:
            if numbers[left] + numbers[right] < target:
                left += 1
            elif numbers[left] + numbers[right] > target:
                right -= 1
            else:
                return [left + 1, right + 1]
        
