// 130-surrounded-regions
public class Solution130 {
    private bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    private void DfsLandMarker(char[][] board, int x, int y) {
        int m = board.Length, n = board[0].Length;

        if (!isValid(x, y, m, n) || board[x][y] != 'O') {
            return;
        }

        board[x][y] = 'V';

        DfsLandMarker(board, x + 1, y);
        DfsLandMarker(board, x - 1, y);
        DfsLandMarker(board, x, y + 1);
        DfsLandMarker(board, x, y - 1);

        return;
    }
    public void Solve(char[][] board) {
        // if the land touches the edge, it is not surrounded
        // and it should be reachable from the edge
        // run dfs starting from all edges and mark O's as V's
        for (int i = 0; i < board.Length; i++) {
            DfsLandMarker(board, i, 0);
            DfsLandMarker(board, i, board[0].Length - 1);
        }
        for (int i = 0; i < board[0].Length; i++) {
            DfsLandMarker(board, 0, i);
            DfsLandMarker(board, board.Length - 1, i);
        }

        // convert remaining O's to X and V's to O
        for (int i = 0; i < board.Length; i++) {
            for (int j = 0; j < board[0].Length; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
            }
        }
    }
}
