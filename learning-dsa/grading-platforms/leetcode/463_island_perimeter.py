class Solution:
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        # print(grid)
        Solution.add_sentinels(grid)
        p = 0
        for i in range(1, len(grid) - 1):
            for j in range(1, len(grid[0]) - 1):
                if grid[i][j]:
                    p += Solution.outer_stripes(grid, i, j)
        return p

    @staticmethod
    def outer_stripes(grid, i, j):

        neighbours = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]
        res = 0
        for x, y in neighbours:
            if grid[x][y] == 0:
                res += 1
        return res

    @staticmethod
    def add_sentinels(grid):
        for row in grid:
            row.insert(0, 0)
            row.append(0)
        grid.insert(0, [0] * len(grid[0]))
        grid.append([0] * len(grid[0]))


s = Solution()
s.islandPerimeter([[0, 1, 0, 0],
                   [1, 1, 1, 0],
                   [0, 1, 0, 0],
                   [1, 1, 0, 0]])
