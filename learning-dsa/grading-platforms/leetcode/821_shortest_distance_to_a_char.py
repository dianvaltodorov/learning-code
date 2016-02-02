import itertools


class Solution:
    def shortestToChar(self, S, C):
        n = len(S)
        res = [n] * n
        pos = -n
        for i in itertools.chain(range(n), range(n - 1, -1, -1)):
            if S[i] == C:
                pos = i
            res[i] = min(res[i], abs(i - pos))
        return res


s = Solution()
s.shortestToChar("loveleetcode", 'e')
