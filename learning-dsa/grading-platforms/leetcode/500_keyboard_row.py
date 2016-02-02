row1 = set("qwertyuiop")
row2 = set("asdfghjkl")
row3 = set("zxcvbnm")


class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        res = []
        for w in words:
            set_w = set(w.lower())
            if set_w & row1 == set_w or set_w & row2 == set_w or set_w & row3 == set_w:
                res.append(w)
        return res


s = Solution()
print(s.findWords( ["Hello", "Alaska", "Dad", "Peace"]))
