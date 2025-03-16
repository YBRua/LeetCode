// 463-island-perimeter
public class Solution463 {
    private bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    public int DfsPerimeterFinder(int[][] grid, int x, int y) {
        int m = grid.Length, n = grid[0].Length;
        if (!isValid(x, y, m, n) || grid[x][y] != 1) {
            return 0;
        }

        int cellPerimeter = 0;
        if (x + 1 >= m || grid[x + 1][y] == 0) {
            cellPerimeter++;
        }
        if (x - 1 < 0 || grid[x - 1][y] == 0) {
            cellPerimeter++;
        }
        if (y + 1 >= n || grid[x][y + 1] == 0) {
            cellPerimeter++;
        }
        if (y - 1 < 0 || grid[x][y - 1] == 0) {
            cellPerimeter++;
        }

        grid[x][y] = 2;

        cellPerimeter += DfsPerimeterFinder(grid, x + 1, y);
        cellPerimeter += DfsPerimeterFinder(grid, x - 1, y);
        cellPerimeter += DfsPerimeterFinder(grid, x, y + 1);
        cellPerimeter += DfsPerimeterFinder(grid, x, y - 1);

        return cellPerimeter;
    }

    public int IslandPerimeter(int[][] grid) {
        int m = grid.Length, n = grid[0].Length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return DfsPerimeterFinder(grid, i, j);
                }
            }
        }

        return 0;
    }
}
