from typing import List
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dic = dict()
        for word in wordDict :
            dic[word] = False
        pointer = 0 
        w = ''
        while pointer <len(s) :
            w += s[pointer] 
            pointer += 1
            if w in dic :
                dic[w] = True
                w = ''
        return w == ''
    
sol = Solution()
print(sol.wordBreak("ababababab", ["abab","ab"]))