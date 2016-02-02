class Solution:
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        i = 0
        res = ""
        while i < len(s):
            j = i + k - 1
            if j > len(s) - 1:
                j = len(s) - 1

            while j >= i:
                # print(j)
                res += s[j]
                j -= 1

            i = i + k
            k2i = i + k
            while i < k2i and i < len(s):
                # print(i)/
                res += s[i]
                i += 1
        return res

s = Solution()
s.reverseStr("abcdefg", 2)