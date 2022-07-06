#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
   public:
    const int MOD = 1e9 + 7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> boundaries(nums.size(), 0);
        // for each (start, end)
        // set boundaries[start]++ and [end]--
        // so that a prefix sum of boundaries is the frequency of the index
        for (int i = 0; i < requests.size(); ++i) {
            int start = requests[i][0], end = requests[i][1];
            boundaries[start]++;
            if (end != nums.size() - 1) {
                boundaries[end + 1]--;
            }
        }
        // compute prefix sum
        int counts = 0;
        for (int i = 0; i < boundaries.size(); ++i) {
            counts += boundaries[i];
            boundaries[i] = counts;
        }

        sort(nums.begin(), nums.end(), greater<>());
        sort(boundaries.begin(), boundaries.end(), greater<>());

        long res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res = (((static_cast<long>(nums[i]) % MOD) *
                    (static_cast<long>(boundaries[i]) % MOD)) %
                       MOD +
                   res) %
                  MOD;
        }

        return static_cast<int>(res);
    }
};
