class Solution(object):
    def nextGreaterElement(self, findNums, nums):
        """
        :type findNums: List[int]
        :type nums: List[int]
        :rtype: List[int]
        """

        n = len(nums1)
        m = len(nums2)
        res = [None] * n
        for i in range(n):
            for j in range(i, m):
                if findNums[i] < nums[j]:
                    res[i] = nums[j]
                    break
            else:
                res[i] = -1
        return res


s = Solution()
nums1 = [4, 1, 2]
nums2 = [1, 3, 4, 2]
print(s.nextGreaterElement(nums1, nums2))
nums1 = [2, 4]
nums2 = [1, 2, 3, 4]
print(s.nextGreaterElement(nums1, nums2))
