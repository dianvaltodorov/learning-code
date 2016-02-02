class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        res = []
        return Solution.util(list(S), 0, res)

    @staticmethod
    def util(S, i, res):
        if i >= len(S):
            return res
        elif not S[i].isalpha():
            Solution.util(S, i + 1, res)
        elif S[i].isalpha():
            S[i] = S[i].lower()
            res.append(''.join(S))
            Solution.util(S, i+1, res)
            S[i] = S[i].upper()
            print(S)
            res.append(''.join(S))
            Solution.util(S, i+1, res)
        return res


s = Solution()
print(s.letterCasePermutation('a1b2'))
