// 289-game-of-life
#include <vector>
using namespace std;

class Solution {
   public:
    void gameOfLife(vector<vector<int>>& board) {
        // this is to solve the problem in-place
        // use the least significant bit (0/1) to store current state
        // and the second least significant bit (2/3) to store next state
        // update state by shifting right by 1

        int n_rows = board.size();
        int n_cols = board[0].size();

        const int delta_x[] = {1, 1, 0, -1, -1, -1, 0, 1};
        const int delta_y[] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                // count number of neighbors
                int living_neighbors = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + delta_x[k];
                    int y = j + delta_y[k];
                    if (x >= 0 && x < n_rows && y >= 0 && y < n_cols) {
                        living_neighbors += board[x][y] & 1;
                    }
                }

                if (board[i][j] & 1 == 1) {
                    // living cell
                    if (living_neighbors == 2 || living_neighbors == 3) {
                        // lives when 2 or 3 neighbors
                        board[i][j] |= 2;
                    } else {
                        // dies otherwise
                        board[i][j] &= 1;
                    }
                } else {
                    // dead cell
                    if (living_neighbors == 3) {
                        // becomes alive when 3 neighbors
                        board[i][j] |= 2;
                    } else {
                        // still dead otherwise
                        board[i][j] &= 1;
                    }
                }
            }
        }

        // update state
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
