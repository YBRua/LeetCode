#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> ans(max(n+1, 3));
        ans[1] = 1;
        ans[2] = 2;
        for (int i = 3; i <= n; ++i) {
            ans[i] = ans[i - 1] + ans[i - 2];
        }

        return ans[n];
    }
};
