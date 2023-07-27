class Solution:
    '''
    def lengthOfLongestSubstring(self, s: str) -> int:
        sequences = [''] * len(s)
        for i, c in enumerate(s):
            dic = set(c)
            sequences[i] += c
            for j in range(i+1, len(s)):
                if s[j] not in dic:
                    dic.add(s[j])
                    sequences[i] += s[j]
                else :
                    break
        return max([len(e) for e in sequences])
    '''
    def lengthOfLongestSubstring(self, s: str) -> int:
        sequences = [''] * len(s)
        for i, c in enumerate(s):
            sequences[i] += c
            for j in range(i+1, len(s)):
                if s[j] not in sequences[i]:
                    sequences[i] += s[j]
                else :
                    break
        return max([len(e) for e in sequences])

sol = Solution()
print(sol.lengthOfLongestSubstring("bbbbb"))

