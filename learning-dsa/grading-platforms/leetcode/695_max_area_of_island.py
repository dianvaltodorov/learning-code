class Solution:
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        Solution.put_sentinels(grid)
        max_area = 0
        for i in range(1, len(grid) - 1):
            for j in range(1, len(grid[0]) - 1):
                if grid[i][j]:
                    area = Solution.area_util(grid, i, j, 1)
                    if max_area < area:
                        max_area = area
        return max_area

    @staticmethod
    def area_util(grid, i, j, count):
        grid[i][j] = 0
        neighbours = [(i + 1, j), (i - 1, j), (i, j - 1), (i, j + 1)]
        for i, j in neighbours:
            if grid[i][j]:
                count = 1 + Solution.area_util(grid, i, j, count)
        return count

    @staticmethod
    def put_sentinels(grid):
        for row in grid:
            row.insert(0, 0)
            row.append(0)
        grid.append([0] * len(grid[0]))
        grid.insert(0, [0] * len(grid[0]))


mat = [[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
       [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
       [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
       [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
       [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]]

mat = [[1]]

s = Solution()
print(s.maxAreaOfIsland(mat))
