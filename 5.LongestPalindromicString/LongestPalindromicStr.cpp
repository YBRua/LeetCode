#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        // dp[i][j] = 1 if s[i:j+1] is a palindrome else 0
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // one element, size == 0
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        // two elements, size == 1
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i+1] = 1;
            }
        }

        for (int size = 2; size < n; ++size) {
            for (int start = 0; start < n - size; ++start) {
                int end = start + size; // inclusive

                // if inner is a palindrome and outer equals
                if (s[start] == s[end] && dp[start+1][end-1]) {
                    dp[start][end] = 1;
                }
            }
        }

        int begin = 0;
        int end = 0;
        int max_val = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (dp[i][j] && j - i > max_val) {
                    max_val = j - i;
                    begin = i;
                    end = j;
                }
            }
        }

        return s.substr(begin, end - begin + 1);
    }
};

int main() {
    string test_case = "aacabdkacaa";
    printf(Solution().longestPalindrome(test_case).c_str());
}
