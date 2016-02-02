from collections import Counter

LINE = 100
class Solution:
    def numberOfLines_fail(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        occurrences = Counter(S)
        content = 0
        for c, count in occurrences.items():
            w = widths[ord(c) - ord('a')]
            content += count * w
        print(content)
        print(occurrences)
        return [content // 100 + bool(content % 100),  content % 100]

    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """

        lines = 1
        units = 0
        i = 0
        while i < len(S):
            w = widths[ord(S[i]) - ord('a')]
            if units + w > LINE:
                lines += 1
                units = 0
            else:
                units = units + w
                i += 1

        return [lines, units]







s = Solution()
widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]
print(s.numberOfLines(widths, "bbbcccdddaaa"))