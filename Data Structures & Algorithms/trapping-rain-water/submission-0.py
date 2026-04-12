class Solution:
    def trap(self, height: List[int]) -> int:
        # prefix
        prefix = []
        suffix = []
        max_h = 0
        for h in height:
            if h > max_h:
                max_h = h
            prefix.append(max_h)
        max_h = 0
        for h in reversed(height):
            if h > max_h:
                max_h = h
            suffix.append(max_h)
        # water at i = min(height[l],height[r]) - height[i]
        water = 0
        for i in range(len(height)):
            water += (min(prefix[i], suffix[len(height)-1-i]) - height[i])
        
        return water
