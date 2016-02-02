class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        i = 0
        j = len(s) - 1

        while i < j:
            while not s[i].isalnum() and i < j:
                i += 1

            while not s[j].isalnum() and i < j:
                j -= 1

            print(s[i], s[j])
            if not self.are_equal(s[i], s[j]):
                return False

            i += 1
            j -= 1

        return True

    def are_equal(self, a, b):
        x = a.lower()
        y = b.lower()
        return x == y


s = Solution()
# assert not s.isPalindrome("race a car")
# assert s.isPalindrome("race a e car")
assert s.isPalindrome("A man, a plan, a canal: Panama")
