using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution994 {
        // 994-rotting-oranges
        public int OrangesRotting(int[][] grid) {
            var bfsq = new Queue<(int, int)>();
            int m = grid.Length;
            int n = grid[0].Length;

            int numFresh = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 2) {
                        bfsq.Enqueue((i, j));
                    }
                    if (grid[i][j] == 1) {
                        numFresh += 1;
                    }
                }
            }

            int nMinutes = 0;
            while (bfsq.Count > 0) {
                nMinutes += 1;

                int currentRound = bfsq.Count;
                for (int k = 0; k < currentRound; ++k) {
                    var (x, y) = bfsq.Dequeue();
                    grid[x][y] = 2;
                    numFresh -= 1;
                    foreach (var (dx, dy) in new List<(int, int)>([(1, 0), (0, 1), (-1, 0), (0, -1)])) {
                        if (x + dx >= 0 && x + dx < m && y + dy >= 0 && y + dy < n && grid[x + dx][y + dy] == 1) {
                            bfsq.Enqueue((x + dx, y + dy));
                        }
                    }
                }
            }

            if (numFresh > 0) {
                return -1;
            }

            return nMinutes;
        }
    }
}
