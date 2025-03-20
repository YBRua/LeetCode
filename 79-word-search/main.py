from typing import List


# 79-word-search
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n_rows = len(board)
        n_cols = len(board[0])

        def _dfs_word_search(row: int, col: int, idx: int, visited: List[List[bool]]) -> bool:
            if idx == len(word):
                return True

            if row < 0 or row >= n_rows or col < 0 or col >= n_cols:
                return False

            if visited[row][col] or board[row][col] != word[idx]:
                return False

            visited[row][col] = True
            res = (
                _dfs_word_search(row + 1, col, idx + 1, visited)
                or _dfs_word_search(row - 1, col, idx + 1, visited)
                or _dfs_word_search(row, col + 1, idx + 1, visited)
                or _dfs_word_search(row, col - 1, idx + 1, visited)
            )
            visited[row][col] = False

            return res

        for row in range(n_rows):
            for col in range(n_cols):
                if board[row][col] == word[0]:
                    if _dfs_word_search(row, col, 0, [[False] * n_cols for _ in range(n_rows)]):
                        return True

        return False
