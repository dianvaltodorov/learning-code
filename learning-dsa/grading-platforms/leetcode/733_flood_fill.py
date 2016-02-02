class Solution:
    def floodFill(self, image, sr, sc, newColor):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type newColor: int
        :rtype: List[List[int]]
        """
        # Solution.put_sentinels(image)
        Solution.dfs_util(image, sr, sc, newColor)
        for i in range(len(image)):
            for j in range(len(image[0])):
                image[i][j] = abs(image[i][j])
        return image

    @staticmethod
    def dfs_util(image, i, j, newColor):
        neighs = [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)]
        image[i][j] = -newColor
        for x, y in neighs:
            if 0 <= x < len(image) and 0 <= y < len(image[0]) and image[x][y] > 0:
                Solution.dfs_util(image, x, y, newColor)



image = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
sr = 1
sc = 1
newColor = 2
s = Solution()
s.floodFill(image, sr, sc, newColor)

print(image)
