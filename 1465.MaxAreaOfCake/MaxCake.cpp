#include <vector>
#include <algorithm>

using namespace std;

class Solution {
   public:
    const int MOD = 1e9 + 7;
    int maxArea(int h, int w, vector<int>& horizontalCuts,
                vector<int>& verticalCuts) {
        // sort the arrays first
        // how come the inputs are not sorted
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        // append last row/col
        horizontalCuts.push_back(h - horizontalCuts.back());
        verticalCuts.push_back(w - verticalCuts.back());

        // convert cuts into differences
        for (int i = horizontalCuts.size() - 2; i > 0; --i) {
            horizontalCuts[i] = horizontalCuts[i] - horizontalCuts[i - 1];
        }
        for (int j = verticalCuts.size() - 2; j > 0; --j) {
            verticalCuts[j] = verticalCuts[j] - verticalCuts[j - 1];
        }

        int max_h = 0, max_w = 0;
        for (int i = 0; i < horizontalCuts.size(); ++i)
            max_h = max(max_h, horizontalCuts[i]);
        for (int j = 0; j < verticalCuts.size(); ++j)
            max_w = max(max_w, verticalCuts[j]);

        return static_cast<long long>(max_h) * max_w % MOD;
    }
};
