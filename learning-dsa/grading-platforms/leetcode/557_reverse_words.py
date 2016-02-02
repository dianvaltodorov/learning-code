class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = ""
        temp = 0

        for i in range(len(s)):
            if s[i] == " " or i == len(s) - 1:
                if i == len(s) - 1:
                    j = i
                else:
                    j = i - 1

                while j >= temp:
                    res += s[j]
                    j -= 1

                if s[i] == " ":
                    res += " "

                temp = i + 1

        return res


s = Solution()
print(s.reverseWords("asdf qwer hjkl"))
