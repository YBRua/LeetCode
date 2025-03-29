#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        vector<vector<int>> res(s.size(), vector<int>(s.size(), false));

        for (int i = 0; i < s.size(); ++i) {
            res[i][i] = 1;

            if (i > 0 && s[i - 1] == s[i]) {
                res[i - 1][i] = 2;
            }
        }

        for (int len = 2; len <= s.size(); ++len) {
            for (int start = 0; start < s.size(); ++start) {
                int end = start + len - 1;
                if (end >= s.size()) {
                    break;
                }
                if (s[start] == s[end] && res[start + 1][end - 1] != 0) {
                    res[start][end] = res[start + 1][end - 1] + 2;
                }
            }
        }

        int max_len = 0, max_start = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < s.size(); ++j) {
                if (res[i][j] > max_len) {
                    max_len = res[i][j];
                    max_start = i;
                }
            }
        }

        if (max_len != 0) {
            return s.substr(max_start, max_len);
        }

        return "";
    }
};