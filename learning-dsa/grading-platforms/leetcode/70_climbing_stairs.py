class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """

        a = 0
        b = 1
        for i in range(n):
            a, b = b, a + b
        return b

s = Solution( )
print(s.climbStairs(2))