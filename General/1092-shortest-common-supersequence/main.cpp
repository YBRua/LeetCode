#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.size(), len2 = str2.size();
        // shortest common supersequence of str1[i + 1] and str2[j + 1]
        vector<vector<int>> scs(len1 + 1, vector<int>(len2 + 1));

        // scs init
        for (int i = 0; i <= len1; ++i) {
            // str1 is empty so we have to append all of str2
            scs[i][0] = len2;
        }
        for (int j = 0; j <= len2; ++j) {
            // similarly
            scs[0][j] = 0;
        }

        // scs length computation
        for (int row = 1; row <= len1; ++row) {
            for (int col = 1; col <= len2; ++col) {
                if (str1[row] == str2[col]) {
                    // match, scs + 1
                    scs[row][col] = scs[row - 1][col - 1] + 1;
                } else {
                    // not match, choose the shorter one
                    scs[row][col] = min(scs[row][col - 1], scs[row - 1][col]);
                }
            }
        }

        // backtracking
        string res = "";
        int row = len1, col = len2;
        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                res += str1[row - 1];
                row--;
                col--;
            } else if (scs[row - 1][col] < scs[row][col - 1]) {
                res += str1[row - 1];
                row--;
            } else {
                // scs[row - 1][col] > scs[row][col -1]
                res += str2[col - 1];
                col--;
            }
        }

        while (row > 0) {
            res += str1[row - 1];
            row--;
        }
        while (col > 0) {
            res += str2[col - 1];
            col--;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
