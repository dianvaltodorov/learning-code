class Solution(object):
    def judgeCircle_fail(self, moves):
        """
        :type moves: str
        :rtype: bool
        """

        if len(moves) == 0:
            return False

        stack = [moves[0]]
        for m in moves[1:]:
            if m == 'U':
                if stack and stack[-1] == 'D':
                    stack.pop()
                else:
                    stack.append(m)
            elif m == 'D':
                if stack and stack[-1] == 'U':
                    stack.pop()
                else:
                    stack.append(m)
            elif m == 'L':
                if stack and stack[-1] == 'R':
                    stack.pop()
                else:
                    stack.append(m)
            elif m == 'R':
                if stack and stack[-1] == 'L':
                    stack.pop()
                else:
                    stack.append(m)
            else:
                raise Exception('Unknown move')

        return len(stack) == 0

    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """

        counts = {
            'U': 0,
            'D': 0,
            'L': 0,
            'R': 0
        }

        for m in moves:
            counts[m] += 1

        left_right = counts['R'] == counts['L']
        up_down = counts['U'] == counts['D']
        return left_right and up_down



s = Solution()
assert s.judgeCircle("LLLRRR") == True
assert s.judgeCircle("UD") == True
assert s.judgeCircle("UUD") == False
assert s.judgeCircle("LLLRRRU") == False
assert s.judgeCircle("RLUURDDDLU") == True
