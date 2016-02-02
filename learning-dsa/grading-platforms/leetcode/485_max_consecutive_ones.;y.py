class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        brs = [0] * len(nums)
        c = 1
        for i in range(len(nums)):
            if nums[i] == 1:
                brs[i] = c
                c = c+ 1
            else:
                c = 1
        return max(brs)
s = Solution()
s.findMaxConsecutiveOnes([1,1,1,1,1,0,0,0,1,1,1])
