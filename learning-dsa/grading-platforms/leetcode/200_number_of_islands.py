class Solution:
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        res = 0
        if not grid:
            return 0
        Solution.put_sentinels(grid)
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == '1':
                    Solution.island_util(grid, i, j)
                    res += 1
        return res

    @staticmethod
    def island_util(grid, i, j):
        grid[i][j] = '0'
        neighs = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]
        for x, y in neighs:
            if grid[x][y] == '1':
                Solution.island_util(grid, x, y)

    @staticmethod
    def put_sentinels(grid):
        for row in grid:
            row.insert(0, '0')
            row.append('0')
        grid.append(['0'] * len(grid[0]))
        grid.insert(0, ['0'] * len(grid[0]))


mat = [["1", "1", "1", "1", "0"],
       ["1", "1", "0", "1", "0"],
       ["1", "1", "0", "0", "0"],
       ["0", "0", "0", "0", "0"]]

mat = []
s = Solution()
print(s.numIslands(mat))
