using System;
using System.Collections.Generic;

namespace Hot100SU2025 {
    public class Solution79 {
        // 79-word-search
        bool found;

        public void Dfs(char[][] board, string word, bool[][] visited, int idx, int x, int y) {
            if (found) {
                return;
            }

            if (board[x][y] != word[idx]) {
                return;
            }

            if (idx == word.Length - 1) {
                found = true;
                return;
            }

            List<(int, int)> vectors = [(1, 0), (0, 1), (-1, 0), (0, -1)];
            foreach (var (dx, dy) in vectors) {
                if (x + dx >= 0 && x + dx < board.Length && y + dy >= 0 && y + dy < board[0].Length && !visited[x + dx][y + dy]) {
                    visited[x + dx][y + dy] = true;
                    Dfs(board, word, visited, idx + 1, x + dx, y + dy);
                    visited[x + dx][y + dy] = false;
                }
            }
        }

        public bool Exist(char[][] board, string word) {
            found = false;
            bool[][] visited = new bool[board.Length][];
            for (int i = 0; i < board.Length; ++i) {
                visited[i] = new bool[board[0].Length];
            }

            for (int i = 0; i < board.Length; ++i) {
                for (int j = 0; j < board[0].Length; ++j) {
                    visited[i][j] = true;
                    Dfs(board, word, visited, 0, i, j);
                    visited[i][j] = false;
                }
            }

            return found;
        }
    }
}
