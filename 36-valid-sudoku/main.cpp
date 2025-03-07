#include <vector>
using namespace std;

class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9];
        int cols[9][9];
        int grids[3][3][9];

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    continue;
                }

                int val = board[row][col] - '0' - 1;
                rows[row][val] += 1;
                if (rows[row][val] > 1)
                    return false;

                cols[col][val] += 1;
                if (cols[col][val] > 1)
                    return false;

                grids[row / 3][col / 3][val] += 1;
                if (grids[row / 3][col / 3][val] > 1)
                    return false;
            }
        }

        return true;
    }
};