class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        br = 0
        s = list(set(nums))
        print(s)
        for i in range(len(s)):
            for j in range(i + 1, len(s)):
                if abs(s[i] - s[j]) == k:
                    br += 1
        return br


s = Solution()
# print(s.findPairs([1,1,1,2,1], 1))
print(s.findPairs([1, 3, 1, 5, 4], 0))
