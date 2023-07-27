from typing import List
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        answer_set = set()
        for i, pivot_1 in enumerate(nums):
            for j in range(i+1, len(nums)-1):
                pivot_2 = nums[j]
                loc = pivot_1 + pivot_2
                l, r  = j+1, len(nums)-1
                while l < r :
                    s = loc + nums[l] + nums[r]
                    if s == target:
                        answer_set.add((pivot_1,pivot_2, nums[l], nums[r]))
                        l, r = l+1, r-1
                    elif s < target :
                        l += 1
                    else :
                        r -= 1
        return [list(e) for e in answer_set]
nums = [1,0,-1,0,-2,2]
target = 0
sol = Solution()
print(sol.fourSum(nums,target))