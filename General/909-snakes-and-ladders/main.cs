// 909-snakes-and-ladders
using System.Collections.Generic;

public class Solution909 {
    private int n;
    private (int, int) getCoordinates(int num) {
        int row = n - (num - 1) / n - 1;
        if (row % 2 != n % 2) {
            int col = (num - 1) % n;
            return (row, col);
        } else {
            int col = n - 1 - (num - 1) % n;
            return (row, col);
        }
    }

    public int SnakesAndLadders(int[][] board) {
        n = board.Length;
        int[] dists = new int[n * n + 1];
        for (int i = 0; i < n * n + 1; ++i) {
            dists[i] = int.MaxValue;
        }

        Queue<int> queue = new();
        queue.Enqueue(1);
        dists[1] = 0;

        while (queue.Count > 0) {
            int curr = queue.Dequeue();
            // Console.WriteLine($"Current: {curr}, {dists[curr]}");

            if (curr == n * n) {
                return dists[curr];
            }

            if (curr > n * n) {
                continue;
            }

            for (int i = 1; i <= 6; ++i) {
                int next = curr + i;

                if (next > n * n) {
                    break;
                }

                var (row, col) = getCoordinates(next);
                // Console.WriteLine($"-> Next: {next} ({row}, {col}), {dists[curr] + 1}");

                // warp
                if (board[row][col] != -1) {
                    next = board[row][col];
                    // Console.WriteLine($"-> Warp: {next}, {dists[curr] + 1}");
                }

                if (dists[next] != int.MaxValue) {
                    continue;
                }

                dists[next] = dists[curr] + 1;
                queue.Enqueue(next);
            }
        }

        return -1;
    }
}
