using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution200 {
        // 200-number-of-islands
        public void BfsMarkAndRemove(char[][] grid, int x, int y) {
            Queue<(int, int)> bfsq = new();
            List<(int, int)> deltas = [(0, 1), (0, -1), (1, 0), (-1, 0)];

            int m = grid.Length;
            int n = grid[0].Length;

            bfsq.Enqueue((x, y));
            while (bfsq.Count > 0) {
                var (currX, currY) = bfsq.Dequeue();
                if (grid[currX][currY] != '1') {
                    continue;
                }
                grid[currX][currY] = '0';


                foreach (var (dx, dy) in deltas) {
                    int newX = currX + dx, newY = currY + dy;
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == '1') {
                        bfsq.Enqueue((newX, newY));
                    }
                }
            }

            return;
        }

        public int NumIslands(char[][] grid) {
            int m = grid.Length;
            int n = grid[0].Length;

            int numIslands = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == '1') {
                        numIslands += 1;
                        // grid[i][j] = '0';
                        BfsMarkAndRemove(grid, i, j);
                    }
                }
            }

            return numIslands;
        }
    }
}
