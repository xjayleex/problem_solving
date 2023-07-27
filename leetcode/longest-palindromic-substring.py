class Solution:
    def longestPalindrome(self, s: str) -> str:
        threshold = len(s) - 1
        max_len = 0
        answer = ''
        for i, pivot in enumerate(s):
            left, right = i, i
            while right + 1 <= threshold and pivot[0] == s[right+1]:
                right += 1
                pivot += s[right]

            while left - 1 >= 0 and right + 1 <= threshold:
                left, right = left - 1, right + 1
                if s[left] != s[right] :
                    break
                pivot = s[left] + pivot + s[right]
            if len(pivot) > max_len :
                max_len = len(pivot)
                answer = pivot
        return answer


sol = Solution()
print(sol.longestPalindrome("ccc"))

