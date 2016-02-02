class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        def transform(x):
            if x % 3 == 0 and x % 5 == 0:
                return "FizzBuzz"
            elif x % 3 == 0:
                return "Fizz"
            elif x % 5 == 0:
                return "Buzz"
            else:
                return str(x)

        return [transform(i) for i in list(range(1, n + 1))]


s = Solution()
print(s.fizzBuzz(3))
