// 200-number-of-islands
public class Solution200 {
    public void DfsMarkIsland(char[][] grid, int x, int y, char current) {
        if (x < 0 || x >= grid.Length || y < 0 || y >= grid[0].Length || grid[x][y] != '1') {
            return;
        }

        grid[x][y] = current;
        if (x - 1 >= 0 && grid[x - 1][y] == '1') {
            DfsMarkIsland(grid, x - 1, y, current);
        }
        if (x + 1 < grid.Length && grid[x + 1][y] == '1') {
            DfsMarkIsland(grid, x + 1, y, current);
        }
        if (y - 1 >= 0 && grid[x][y - 1] == '1') {
            DfsMarkIsland(grid, x, y - 1, current);
        }
        if (y + 1 < grid[0].Length && grid[x][y + 1] == '1') {
            DfsMarkIsland(grid, x, y + 1, current);
        }

        return;
    }

    public int NumIslands(char[][] grid) {
        int nRows = grid.Length, nCols = grid[0].Length;
        char current = 'a';
        int numIslands = 0;

        for (int i = 0; i < nRows; i++) {
            for (int j = 0; j < nCols; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    DfsMarkIsland(grid, i, j, current);
                    current++;
                }
            }
        }

        return numIslands;
    }
}