from typing import List
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        answer = []
        def _dfs(made, used_left_side, n):

            if len(made) == n * 2:
                answer.append(made)
                return

            if used_left_side < n:
                _dfs(made + '(', used_left_side + 1, n)
            if len(made) - used_left_side < used_left_side: 
                _dfs(made + ')', used_left_side, n)
        
        _dfs(made='(', used_left_side=1, n=n)
        return answer
            
sol = Solution()
print(sol.generateParenthesis(3))

