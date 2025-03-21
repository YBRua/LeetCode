// 73-set-matrix-zeroes
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows, cols;
        int m = matrix.size(), n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (int i : rows) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }

        for (int j : cols) {
            for (int i = 0; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }

        return;
    }
};
