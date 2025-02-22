#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixes(n, 0), suffixes(n, 0);

        prefixes[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixes[i] = prefixes[i - 1] * nums[i];
        }
        suffixes[n - 1] = nums[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            suffixes[j] = suffixes[j + 1] * nums[j];
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ans[i] = suffixes[i + 1];
                continue;
            }
            if (i == n - 1) {
                ans[i] = prefixes[i - 1];
                continue;
            }
            ans[i] = suffixes[i + 1] * prefixes[i - 1];
        }

        return ans;
    }
};