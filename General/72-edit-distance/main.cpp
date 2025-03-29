#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    inline int min_among_three(int a, int b, int c) {
        int min;
        min = a < b ? a : b;
        min = min < c ? min : c;

        return min;
    }

    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();
        vector<vector<int>> edit_dists(len1 + 1, vector<int>(len2 + 1));

        for (int i = 1; i <= len1; ++i) {
            edit_dists[i][0] = i;
        }
        for (int j = 1; j <= len2; ++j) {
            edit_dists[0][j] = j;
        }

        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int sub_cost = word1[i - 1] == word2[j - 1] ? 0 : 1;
                sub_cost = edit_dists[i - 1][j - 1] + sub_cost;
                int min_val = min_among_three(edit_dists[i][j - 1] + 1, edit_dists[i - 1][j] + 1, sub_cost);
                edit_dists[i][j] = min_val;
            }
        }

        return edit_dists[len1][len2];
    }
};