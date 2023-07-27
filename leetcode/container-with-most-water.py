from typing import List
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        answer = 0 
        def _calc_area(x, y):
            return x * y 
        while l < r :
            local_maxima = _calc_area(r-l,min(height[l],height[r]))
            answer = answer if answer > local_maxima else local_maxima
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return answer
    
sol = Solution()
print(sol.maxArea([1,8,6,2,5,4,8,3,7]))



